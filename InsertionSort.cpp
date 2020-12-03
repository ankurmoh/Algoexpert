#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  int i,j,sz=array.size(),key;
	if(sz==0)
  	return {};
	for(i=1;i<sz;i++)
	{
		key=array[i];
		j=i-1;
		while((j>=0) && (array[j]>key))
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
	return array;
}
