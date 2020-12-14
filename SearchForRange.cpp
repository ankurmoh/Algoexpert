#include <vector>
using namespace std;
int binary(vector<int>& array,int target)
{
	int mid,left=0,right=array.size();
	while(left<right)
	{
		mid = left + (right-left)/2;
		if(array[mid]<target)
			left=mid+1;
		else
			right=mid;
	}
	return left;
}
vector<int> searchForRange(vector<int> array, int target) {
  int i,sz=array.size();
	if(sz==0)
  	return {};
	int l = binary(array,target);
	if((l == -1) || (array[l]!=target))
	{
		return {-1,-1};
	}
	int r = binary(array,target+1)-1;
	return {l,r};
}
