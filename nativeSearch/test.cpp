#include "test.h"
#include "nativeSearch.h"

const size_t TESTED_ARRAY_LENGTH = 10;

int testArray[TESTED_ARRAY_LENGTH] = {11,5,3,8,17,7,44,6,2,14};
bool error = false;
int key = 44;

//int SimpleNativeSearch(int* arr, size_t& length, int& key, bool& error)
//int VectorNativeSearch(std::vector<int>& arr, int& key, bool& error)
//int search_3(std::vector<int>& v, int key)

//int rc = SimpleNativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
//    for(auto& x : v) {
//        o << x << ", ";
    for(int i = 0; i < v.size(); ++i) {
      o << v[i] << ", ";
    }
    return o << "]";
}

//(*SimpleNativeSearch)(int*, size_t&, int, bool)
template <class TFunc, class TResult, class TParam1, class TParam2,
	  class TParam3, class TParam4>
void testSimple(TResult expect, TFunc(*)(int*, size_t&, int, bool), TParam1* p1, TParam2 p2, TParam3 p3,
		TParam3 p4) {
	auto got = f(p1, p2, p3, p4);
	if(got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}

template <class TFunc, class TResult, class TParam1, class TParam2,
	  class TParam3>
void testVector(TResult expect, TFunc f, TParam1 p1, TParam2 p2, TParam2 p3) {
	auto got = f(p1, p2, p3);
    if(got != expect) {
        cerr << "failed: f(" << p1 << ", " << p2 << ") = "
            << got << " != " << expect << endl;
    }
}

template <class TFunc, class TResult, class TParam1, class TParam2>
void testSearch3(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
    auto got = f(p1, p2);
    if(got != expect) {
        cerr << "failed: f(" << p1 << ", " << p2 << ") = "
            << got << " != " << expect << endl;
    }
}

testSimple<int, (*SimpleNativeSearch)(int*, size_t&, int, bool), int*, size_t&, int, bool>(10, SimpleNativeSearch, testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
//int rc = SimpleNativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
