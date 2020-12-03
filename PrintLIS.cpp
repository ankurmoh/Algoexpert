#include <vector>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> array) {
  int i,sz=array.size(),j,maxi=1,ind=0,k;
	if(sz==0)
  	return {};
	vector<int>dp(sz,1);
	for(i=1;i<sz;i++)
	{
		for(j=0;j<i;j++)
		{
			if((array[i]>array[j]) && (dp[i]<dp[j]+1))
				dp[i]=dp[j]+1;
		}
	}
	for(i=0;i<sz;i++)
	{
		if(dp[i]>maxi)
		{
			maxi=dp[i];
			ind=i;
		}
	}
	k=maxi;
	vector<int>res;
	i=sz-1;
	while((res.size()<k) && (i>=0))
	{
		if(dp[i]==maxi)
		{
			res.push_back(array[i]);
			maxi--;
		}
		i--;
	}
	reverse(res.begin(),res.end());
	return res;
}
