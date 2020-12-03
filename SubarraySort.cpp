#include <vector>
using namespace std;

bool outoforder(int x,vector<int>& array)
{
	if(x==0)
	{
		if(array[x]>array[x+1])
			return true;
		return false;
	}
	if(x==array.size()-1)
	{
		if(array[x]<array[x-1])
			return true;
		return false;
	}
	if((array[x]<array[x-1]) || (array[x]>array[x+1]))
		return true;
	return false;
}
vector<int> subarraySort(vector<int> array) {
  int i,sz=array.size(),max_elem=INT_MIN,min_elem=INT_MAX,j;
	if(sz==0)
  	return {};
	for(i=0;i<sz;i++)
	{
		if(outoforder(i,array))
		{
			//cout<<i;
			max_elem=max(max_elem,array[i]);
			min_elem=min(min_elem,array[i]);
		}
	}
	//cout<<max_elem<<" "<<min_elem;
	if((max_elem==INT_MIN) && (min_elem==INT_MAX))
		return {-1,-1};
	i=0;
	while(array[i]<=min_elem)
		i++;
	j=sz-1;
	while(array[j]>=max_elem)
		j--;
	return {i,j};
}
