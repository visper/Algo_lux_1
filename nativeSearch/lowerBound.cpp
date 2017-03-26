#include <iostream>
#include <vector>

using namespace std;


//sorted
int* lowerBound(int* begin, int* end, int key)
{
	while(begin < end) {
		int* mediana = begin + (end - begin) / 2;

		if(*mediana < key) {
			begin = mediana+1;
		}
		else {
			end = mediana;
		}
	}

	return begin;
}

int main()
{
//	vector<int> v({1,5,6,8,8,9,11,45,67});
	const size_t TESTED_ARRAY_LENGTH = 13;
	int testArray[TESTED_ARRAY_LENGTH] = {1,12,222,334,454,564,564,564,564,623,767,844,954};

	int* result = lowerBound(testArray, testArray+13, 564);

	cout << testArray+5 << " "  << *result << " " << result << endl;

	return 0;
}
