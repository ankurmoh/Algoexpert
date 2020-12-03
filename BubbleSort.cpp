#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  int i,j,sz=array.size(),temp;
	for(i=0;i<sz;i++)
	{
		for(j=i+1;j<sz;j++)
		{
			if(array[i]>array[j])
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	return array;
}
