#include "common.h"
#include "test.h"
#include "nativeSearch.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "hello\n";
	//	system("pause");

	const size_t TESTED_ARRAY_LENGTH = 10;

	int testArray[TESTED_ARRAY_LENGTH] = {11,5,3,8,17,7,44,6,2,14};
	bool error = false;
	int key = 44;
	
	testSimple(key, SimpleNativeSearch, testArray, const_cast<size_t&>(TESTED_ARRAY_LENGTH), key, error );
	
	return 0;
}
