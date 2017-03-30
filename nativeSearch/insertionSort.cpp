#include <iostream>
#include <vector>

using namespace std;

//insertion sort 
//best O(n^2)
//worst O(n)
//this sort is working good in case if alghorithm partly sorted. In this case
//algo works O(n) time

//[1),[12],[222,334,454,564,564,564,564,623,767,844,954)e
// b   index
//     r_itr
//          index++


void insertionSort(int* b, int* e)
{
	//b+e = [sorted)[index][unsorted)
	int* index = b+1; //index to next
	while(index < e) {//unsorted
		int* r_itr = index; // iterator to sorted
		size_t diff = r_itr - b;


//		swap(r_itr,itr);
		++index;
	}
}

int main()
{
	const size_t TESTED_ARRAY_LENGTH = 13;
	int testArray[TESTED_ARRAY_LENGTH] = {1,12,222,334,454,564,564,564,564,623,767,844,954};

	insertionSort( testArray, testArray+13 );

	return 0;
}
