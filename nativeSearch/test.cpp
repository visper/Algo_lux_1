#include "test.h"
#include "nativeSearch.h"
#include "binarySearch.h"

template <class T>
ostream& operator<<(ostream& o, const vector<T>& v) {
	o << "[";
	for(auto& x : v) {
		o << x << ", ";
	}
	return o << "]";
}

template <class TFunc, class TResult, class TParam1>
void test(TResult expect, TFunc f, TParam1 p1) {
	auto got = f(p1);
	if(got != expect) {
		cerr << "failed: " << expect << " != " << got << endl;
	}
}

template <class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2) {
	auto got = f(p1, p2);
	if(got != expect) {
		cerr << "failed: f(" << p1 << ", " << p2 << ") = "
		     << got << " != " << expect << endl;
	}
}

template <class TFunc, class TResult, class TParam1, class TParam2,
	  class TParam3, class TParam4 >
void test(TResult expect, TFunc f, TParam1 p1, TParam2 p2,
	  TParam3 p3, TParam4 p4) {
	auto got = f(p1, p2, p3, p4);
	if(got != expect) {
		cerr << "failed: f(" << p1 << ", " << p2 << ", " 
		     << p3 << ", " << p4 << ") = "
		     << got << " != " << expect << endl;
	}
}

//int SimpleNativeSearch(int* arr, size_t& length, int& key, bool& error)
//int VectorNativeSearch(std::vector<int>& arr, int& key, bool& error)
//int search_3(std::vector<int>& v, int key)

//int rc = SimpleNativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
/*
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
*/
/*
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
*/
/*
  testSimple<int, (*SimpleNativeSearch)(int*, size_t&, int, bool), int*, size_t&, int, bool>(10, SimpleNativeSearch, testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
//int rc = SimpleNativeSearch(testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error);
*/

void testSimple(int expected, int (*SimpleNativeSearch)(int*, size_t&, int&, bool&), int* array, size_t& len, int& key, bool& flag)
{
	auto got = SimpleNativeSearch(array, len, key, flag);
	if(got != expected) {
		cerr << "failed: " << expected << " != " << got << endl;
	}
	else {
		cout << "success" << endl;
	}
}

/*
  void testSearch_3(int expected, int (*search_3)(vector<int> v, int&), vector<int> v, int& key)
  {
  auto got = search_3(v, key);
  if(got != expected) {
  cerr << "failed: " << expected << " != " << got << endl;
  }
  else {
  cout << "success" << endl;
  }
  }
*/

void test_search() {

	typedef vector<int> Array;

	//trulyMyBinarySearch
	//    auto search = search_2;
	auto search = trulyMyBinarySearch;

	auto key = 8;
	// key not exists in array
        test(-1, search, Array(), 0, (Array()).size(), key); // degerate
        test(-1, search, Array({key-1}),
	     0, (Array({key-1})).size(), key); // trivial
        test(-1, search, Array({key-1, key+1}),
	     0, (Array({key-1, key+1})).size(), key); // trivial2
        test(-1, search, Array({1,2,3,4,5,7}), 
	     0, (Array({1,2,3,4,5,7})).size(), key); // general
        test(-1, search, Array({9,10,11,12}), 
	     0, (Array({9,10,11,12})).size(), key); // general
        test(-1, search, Array({4,1,2,7,10}), 
	     0, (Array({4,1,2,7,10})).size(), key); // general
	// key exists in array
        // non appliable // degerate
        test(0, search, Array({key}), 0, (Array({key})).size(), key); // trivial
        test(0, search, Array({key, key+1}), 
	     0, (Array({key, key+1})).size(), key); // trivial2
        test(1, search, Array({key-1, key}), 
	     0, (Array({key-1, key})).size(), key); // trivial2
        test(8, search, Array({0,1,2,3,4,5,6,7,key}), 
	     0, (Array({0,1,2,3,4,5,6,7,key})).size(), key); // general
        test(0, search, Array({key, 9,10,11,12}),
	     0, (Array({key, 9,10,11,12})).size(), key); // general
        test(2, search, Array({4,1,key,7,10}),
	     0, (Array({4,1,key,7,10})).size(), key); // general                
        
        test(0, search, Array({key,1,key,7,10}),
	     0, (Array({key,1,key,7,10})).size(), key); // general        
        test(2, search, Array({2,1,key,7,key}),
	     0, (Array({2,1,key,7,key})).size(), key); // general       
}
