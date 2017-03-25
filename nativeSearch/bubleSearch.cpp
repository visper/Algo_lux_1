#include <iostream>
#include <vector>

using namespace std;

void bubleSearch(vector<int> v)
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
  for(int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
}

int main()
{
  bubleSearch(vector<int>({4,1,2,10,7,6}));


  return 0;
}
