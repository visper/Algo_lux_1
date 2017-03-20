#include "common.h"
#include "test.h"
#include "nativeSearch.h"
#include "binarySearch.h"

using namespace std;

int main(int argc, char** argv)
{
  /*
	cout << "hello\n";
	//	system("pause");

	const size_t TESTED_ARRAY_LENGTH = 10;

	int testArray[TESTED_ARRAY_LENGTH] = {11,5,3,8,17,7,44,6,2,14};
	vector<int> inputArr;
	inputArr.push_back(11);
	inputArr.push_back(5);
	inputArr.push_back(3);
	inputArr.push_back(8);
	inputArr.push_back(17);
	inputArr.push_back(7);
	inputArr.push_back(44);
	inputArr.push_back(6);
	inputArr.push_back(2);
	inputArr.push_back(14);

	bool error = false;
	int key = 44;
	
	testSimple(6, SimpleNativeSearch, testArray, 
		   const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error );

	//	testSearch_3(6, search_3, inputArr, key);
	
	//	binary_search(const vector<int>& v, int key);
	*/
	typedef vector<int> Array;
	Array v = Array({1,12,222,334,454,564,623,767,844,954});
	//	size_t b = v.begin();
	size_t e = v.size();

	//	cout << binary_search_my(v, 0, e, 4);

	//	int rc = binary_search_my_imperative(v, 767);

	int rc = trulyMyBinarySearch(v, 0, e, 767);
	cout << rc << endl;

	return 0;
}
