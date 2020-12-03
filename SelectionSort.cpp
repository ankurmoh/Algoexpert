#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  int i,j,sz=array.size(),minindex;
	if(sz==0)
  	return {};
	for(i=0;i<sz-1;i++)
	{
		minindex=i;
		for(j=i+1;j<sz;j++)
		{
			if(array[minindex]>array[j])
				minindex=j;
		}
		swap(array[i],array[minindex]);
	}
	return array;
}
