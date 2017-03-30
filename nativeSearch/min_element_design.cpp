#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

namespace my
{
	//min element in unsorted array
	template< class ForwardIt >
	ForwardIt min_element( ForwardIt first, ForwardIt last )
	{
		ForwardIt result = first;
		++first;
		while(first < last) {
			if(*first < *result) {
				result = first;
			}
			++first;
		}
		return result;
	}
}

//если пишем алгоритм и определяем оператор сравнение нужно чтобы выполнялась
//транзитивность a < b b < c => a < c

//есть inplace алгоритмы и outer
// outer те, которые делают что-то наружу. inplace - те, которые нарушают 
// целосность алгоритма

//teta используется когда алгоритм ведёт себя строго, например lower bound

template <class TIter>
void naive_sort(TIter b, TIter e)
{
	for(auto i = b; i < e; ++i) {
		assert(std::is_sorted(b,i));
		// [sorted) U [unsorted)

		for(auto j = i+1; j < e; ++j) {
			// [unsorted) = [i+1, j) [j,e)
			assert(min_element(i, j) == i);

			if(*j < *i)
				swap(*i, *j);

			assert(min_element(i, j) == i);
		}
		assert(is_sorted(b,i+1));
	}
}

//нормальный алгоритм это n*lon(n) и лучше

//гаусовская
//арифмитическая прогрессия это  1  2  3  4  5  6  7  8  9  10
//                              10  9  8  7  6  5  4  3  2  1 
//                              11 11 11 11 11 11 11 11 11 11
//этот алгоритм n^2

template <class TIter>
void selection_sort(TIter b, TIter e)
{
	for(auto i = b; i < e-1; ++i) {
		// [sorted) U [unsorted) = [b, i) U [i, e)
		assert(is_sorted(b,i));
		swap(*i, *min_element(i, e));
	}
}

int main()
{
	vector<int> arr = vector<int>({5,7,2,9,33,6,2,4,32});
	/*
	  tests:
	  -empty - degenerate
	 */

//	std::vector<int>::iterator it = my::min_element(arr.begin(),
//							arr.end() );

//	naive_sort(arr.begin(), arr.end() );
//	cout << *it << endl;

	selection_sort(arr.begin(), arr.end() );

	for(size_t i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
