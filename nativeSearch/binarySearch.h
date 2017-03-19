#include "common.h"
#include <vector>

//int binary_search(const vector<int>& v, int key);
int binary_search_helper(const vector<int> v, size_t begin, size_t end,
			 int key);

int binary_search_my(const vector<int> v, size_t begin, size_t end, int key);
