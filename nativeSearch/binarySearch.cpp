#include "binarySearch.h"

/*
int binary_search_helper
(
	const vector<int>& v,
	size_t begin,
	size_t end,
	int key
)
{
	assert( std::is_sorted(v.begin(), v.end()) );

	if(begin == end) return -1;
	if(end-begin == 1) {
		if(v[begin] == key)
			return begin;
		else
			return -1;
	}

	//[0,m)
	//[m,s)
	//(m-0)+(s-m) = s

        size_t m = (begin + end) / 2;
	// [0, s) ~ [0, m) U [m, s)
	// [b, e) ~ [b, m) U [m, e)

	int rl = binary_search(begin, m);

	if(rl != -1)
		return rl;

	return inr rr = binary_search(m, end);
}
*/

int binary_search_my
(
	const vector<int> v,
	size_t begin,
	size_t end,
	int key
)
{
	if(0 == v.size())
		return -1;

	size_t mediana = v.size() / 2;

	if(key == v[mediana])
		return mediana;

	if(key < v[mediana])
		binary_search_my(v, begin, mediana, key);
	else
		binary_search_my(v, mediana, end, key);

	return -1;
}

