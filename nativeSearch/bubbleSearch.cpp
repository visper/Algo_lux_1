#include <iostream>
#include <vector>

#include "bubbleSearch.h"

using namespace std;


void bubbleSearchSimpleBackward(vector<int> v)
{
	for(size_t i = 0; i < v.size(); ++i) {
		for(size_t j = 0; j < v.size(); ++j) {
			if(v[i] > v[j]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
/*	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		}*/
}

void bubbleSearchSimpleForward(vector<int> v)
{
	for(size_t i = 0; i < v.size(); ++i) {
		for(size_t j = 0; j < v.size(); ++j) {
			if(v[i] < v[j]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
/*	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		}*/
}

void bubbleSearchBetterBackward(vector<int> v)
{
	for(int i = 0; i < v.size(); ++i) {
		for(int j = i; j < v.size(); ++j) {
			if(v[i] < v[j]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
/*	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		}*/
}

void bubbleSearchBetterForward(vector<int> v)
{
	for(int i = 0; i < v.size(); ++i) {
		for(int j = i; j < v.size(); ++j) {
			if(v[i] > v[j]) {
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
/*	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		}*/
}

/*

int main()
{
	bubbleSearchBetterBackward(vector<int>({4,1,2,10,7,6}));
	cout << endl;
	bubbleSearchBetterForward(vector<int>({4,1,2,10,7,6}));
	cout << endl;
	bubbleSearchSimpleBackward(vector<int>({4,1,2,10,7,6}));
	cout << endl;
	bubbleSearchSimpleForward(vector<int>({4,1,2,10,7,6}));

	return 0;
}
*/
