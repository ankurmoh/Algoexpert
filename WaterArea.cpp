#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  int i,sz=heights.size(),current,sum=0;
	vector<int>left(sz),right(sz);
	if(sz==0)
		return 0;
	left[0]=heights[0];
	for(i=1;i<sz;i++)
		left[i]=max(heights[i],left[i-1]);
	right[sz-1]=heights[sz-1];
	for(i=sz-2;i>=0;i--)
		right[i]=max(heights[i],right[i+1]);
	for(i=0;i<sz;i++)
	{
		current = min(left[i],right[i]);
		sum=sum + (current-heights[i]);
	}
	return sum;
}
