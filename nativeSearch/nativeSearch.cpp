#include "nativeSearch.h"

int NativeSearch(int* arr, size_t& length, int& key, bool& error)
{
#if DEBUG
	cout << "test\n";

	if (arr == NULL)
	{
		cout << "input array error" << endl;
		return -1;
	}

	if (length == 0)
	{
		cout << "input length error" << endl;
		return -1;
	}

	if (error == true)
	{
		cout << "input value error" << endl;
		return -1;
	}
#endif

	int end = arr[length-1];
	arr[length - 1] = key;

	if (end == key)
		return length - 1;

	size_t i = 0;
	while (arr[i] != key)
	{
		cout << "track " << "i" << endl; //debug tracking

		++i;
	}

	if (i < length - 1)
		return i;

	error = true;
	return -1;
}
