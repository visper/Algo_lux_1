#include "common.h"

//void test(expect, f, params)

void testSimple(int expected, int (*SimpleNativeSearch)(int*, size_t&,
							int&, bool&),
		int* array, size_t& len, int& key, bool& flag);
/*
void testSearch_3(int expected, int (*search_3)(vector<int> v, int&),
		  vector<int> v, int& key);
*/

template <class TFunc, class TResult, class TParam1>
void test(TResult expect, TFunc f, TParam1 p1);

template <class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2);

template <class TFunc, class TResult, class TParam1, class TParam2,
	  class TParam3, class TParam4 >
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2,
	  TParam3 p3, TParam4 p4);

void test_search();
