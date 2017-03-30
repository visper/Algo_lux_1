#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> arr;

//O(n) in every case
template <class TIter>
void merge(TIter b, TIter m, TIter e, TIter buff)
{
	TIter first = b;
	TIter second = m;
	TIter buffIter = buff;
	
//	assert(is_sorted(*b,*m));
//	assert(is_sorted(m,e));
	
	while(first < m && second < e) {
		if(*first < *second) {
			*buffIter = *first;
			++first;
		}
		else {
			*buffIter = *second;
			++second;
		}
		++buffIter;
//		assert(is_sorted(buff, buffIter));
	}
	copy(b, m, buffIter);
	copy(second, e, buffIter);
//	assert(buffIter - buff == size);
}


template <class TIter>
void merge_sort(TIter b, TIter e, TIter buff)
{
	auto size = e-b;
	if(size > 1) {
		auto m = b + size / 2;
		merge_sort(b, m, buff);
		merge_sort(b, m, buff+(size)/2);
		copy(buff, buff+size, b);
		merge(b, m, e, buff);
	}
//	else {
//		copy(b,e,buff);
//	}
}

int main()
{
	arr input = arr({5,2,4,6,1,3,2,6});
	arr output = arr({5,2,4,6,1,3,2,6});
	merge_sort(input.begin(), input.end(), output.begin());

	for(size_t i = 0; i < input.size(); ++i) {
		cout << input[i] << " ";
	}
	cout << endl;
	

	for(size_t i = 0; i < output.size(); ++i) {
		cout << output[i] << " ";
	}
	cout << endl;

	return 0;
}

