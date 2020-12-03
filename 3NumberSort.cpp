#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  int i,sz=array.size(),con1=0,con2=0,con3=0;
	for(i=0;i<sz;i++)
	{
		if(array[i]==order[0])
			con1++;
		else if(array[i]==order[1])
			con2++;
		else
			con3++;
	}
	i=0;
	while(i<sz)
	{
		if(con1>0)
		{
			array[i]=order[0];
			con1--;
		}
		else if(con2>0)
		{
			array[i]=order[1];
			con2--;
		}
		else
		{
			array[i]=order[2];
			con3--;
		}
		i++;
	}
  return array;
}
