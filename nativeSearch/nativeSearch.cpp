#include "nativeSearch.h"

int SimpleNativeSearch(int* arr, size_t& length, int& key, bool& error)
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
	if (end == key)
		return length - 1;

	arr[length - 1] = key;

	size_t i = 0;
	while (arr[i] != key)
	{
#if DEBUG
		cout << "track " << "i" << endl; //debug tracking
#endif
		++i;
	}

	if (i < length - 1)
		return i;

	error = true;
	return -1;
}

int VectorNativeSearch(std::vector<int>& arr, int& key, bool& error)
{
#if DEBUG
	cout << "test\n";

	if (error == true) {
		cout << "input value error" << endl;
		return -1;
	}
#endif

	arr.push_back(key);

	size_t i = 0;
	while (arr[i] != key) {
#if DEBUG
		cout << "track: " << "i" << endl; //debug tracking
#endif
		++i;
	}

	arr.pop_back();

	if(i != arr.size()) {
		return i;
	}

	error = true;
	return -1;
}

int search_3(std::vector<int>& v, int key) {
    v.push_back(key);
    int i = 0;
    while (v[i] != key) {
        ++i;
    }
    v.pop_back();

    if (i != static_cast<int>(v.size()) ) {
        return i;
    }

    return -1;
}
