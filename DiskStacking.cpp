#include <vector>
using namespace std;
bool inside(vector<int>& a,vector<int>& b)
{
	return ((a[0]<b[0]) && (a[1]<b[1]) && (a[2]<b[2]));
}
vector<vector<int>> diskStacking(vector<vector<int>> disks) {
 vector<vector<int>>res;
	int i,j,sz=disks.size(),maxi,index;
	if(sz==0)
		return res;
	vector<int>height(sz);
	vector<int>parent(sz,-1);
	sort(disks.begin(),disks.end(),[](const vector<int>& a, const vector<int>& b)
			 {
				 return a[2]<b[2];
			 });
	for(i=0;i<sz;i++)
		height[i]=disks[i][2];
	maxi = height[0];
	index=0;
	for(i=1;i<sz;i++)
	{
		vector<int>current = disks[i];
		for(j=0;j<i;j++)
		{
			if(inside(disks[j],disks[i]))
			{
				if(height[i]<height[j] + current[2])
				{
					height[i] = height[j] + current[2];
					parent[i]=j;
				}
			}
		}
		if(maxi<height[i])
		{
			maxi=height[i];
			index=i;
		}
	}
	while(index!=-1)
	{
		res.insert(res.begin(),disks[index]);
		index=parent[index];
	}
	return res;
}
