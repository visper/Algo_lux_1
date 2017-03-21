#include "common.h"
#include <vector>
#include <algorithm>

//int binary_search(const vector<int>& v, int key);
int binary_search_helper(const vector<int> v, size_t begin, size_t end,
			 int key);

int binary_search_my(const vector<int>& v, size_t begin, size_t end, int key);

int binary_search_my_imperative(const vector<int>& v, int key);

int trulyMyBinarySearch(const vector<int>& v, size_t begin, size_t end,
			int key);

int trulyMyBinarySearchIterative(const vector<int>& v, int key);
