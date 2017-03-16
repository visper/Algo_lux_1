#include "common.h"

//void test(expect, f, params)

void testSimple(int expected, int (*SimpleNativeSearch)(int*, size_t&, int&, bool&), int* array, size_t& len, int& key, bool& flag);
