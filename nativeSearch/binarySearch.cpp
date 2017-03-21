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
	const vector<int>& v,
	size_t begin,
	size_t end,
	int key
)
{
/*
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
*/
    assert(std::is_sorted(v.begin(), v.end()));

    if (begin == end) return -1;
    if (end-begin == 1) {
        if (v[begin] == key)
            return begin;
        else
            return -1;
    }

    assert(begin < end);
    // [b, e) = [b, m) U [m, e)
    size_t m = (begin + end) / 2;
    assert((m-begin) + (end-m) == (end-begin));
    if (key < v[m]) {
        return binary_search_my(v, begin, m, key);
    } else if (v[m] < key) {
        return binary_search_my(v, m+1, end, key);
    } else {
        return m;
    }
}

int binary_search_my_imperative
(
	const vector<int>& v,
	int key
)
{
	if(!std::is_sorted(v.begin(), v.end()))
		return -1;

	size_t begin = 0;
	size_t end = v.size();
/*
	if (begin == end) return -1;
	if (end-begin == 1) {
		if (v[begin] == key)
			return begin;
		else
			return -1;
	}
*/
	for(;;)
	{
		if(begin < end)
		{
			// [b, e) = [b, m) U [m, e)
			size_t m = (begin + end) / 2;
			assert((m-begin) + (end-m) == (end-begin));
			if (key < v[m]) {
				end = m;
//				return binary_search_my(v, begin, m, key);
			} else if (v[m] < key) {
				begin = m+1;
//				return binary_search_my(v, m+1, end, key);
			} else {
				return m;
			}
		}
		else {
			return -1;
		}
	}
}

int trulyMyBinarySearch(const vector<int>& v, size_t begin, size_t end, int key)
{
	//[b + e] = [b - m) + [m - e)
	if(! std::is_sorted(v.begin(), v.end()))
		return -1;

	if(begin < end) {
//		int mediana = begin + (end - begin) / 2;
		int mediana = (begin+end) / 2;
		if(key < v[mediana]) {
			return trulyMyBinarySearch(v, begin, mediana, key);
		}
		else if(key > v[mediana]) {
			return trulyMyBinarySearch(v, mediana, end, key);
		}
		else {
			return mediana;
		}
	}
	else {
		return -1;
	}
}

int trulyMyBinarySearchIterative(const vector<int>& v, int key)
{
	return -1;
}
