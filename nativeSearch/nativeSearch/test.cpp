#include "test.h"
#include "nativeSearch.h"
#include <cassert>

#include <iostream>

using namespace std;

const size_t TESTED_ARRAY_LENGTH = 10;


int testArray[TESTED_ARRAY_LENGTH] = {11,5,3,8,17,7,44,6,2,14};

//int NativeSearch(int* arr, size_t& length, int& key, bool& error);
bool error = false;

int key = 44;

//size_t len = const_cast<size_t>(TESTED_ARRAY_LENGTH);
/*
int rc = NativeSearch(testArray, 0, key, error);
rc = NativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, true);
int* arr = NULL;
rc = NativeSearch(arr, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);*/
int rc = NativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
/*
cout << " out " << rc;
cout << " flag " << error;
*/
//cout << "hello1\n";


template <class TFunc, class TResult, class Tparam1>
void test(TResult expect, TFunc f, TParam1 p1);

ostream& operator<< (ostream & o, const vector<T>& v)
{
	o << "[";
	for(auto& )

}

void test(expect, f, params)
{
	auto got = f(params);
	if (got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}


void testSearch()
{
	typedef vector<int> Array;
	test(8, NativeSearch, Array{ 0,1,2,3,4,4,5,6,7 });

}
