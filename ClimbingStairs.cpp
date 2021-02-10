#include<bits/stdc++.h>
using namespace std;

void dfs(int sum,vector<int>& path,vector<vector<int>>& res,int maxSteps)
{
	if(sum<0)
		return;
	if(sum==0)
	{
		res.push_back(path);
		return;
	}
	for(int i=1;i<=maxSteps;i++)
	{
		if(i<=sum)
		{
			path.push_back(i);
			dfs(sum-i,path,res,maxSteps);
			path.pop_back();
		}
	}
}
int staircaseTraversal(int height, int maxSteps) {
	vector<int>path;
	vector<vector<int>>res;
	dfs(height,path,res,maxSteps);
	return res.size();
}
