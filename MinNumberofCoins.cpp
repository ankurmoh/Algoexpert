#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
 vector<int>dp(n+1,INT_MAX);
	dp[0]=0;
	int i,j,sz=denoms.size(),res;
	for(i=1;i<=n;i++)
	{
		res=INT_MAX;
		for(j=0;j<sz;j++)
		{
			if((i>=denoms[j]) && (dp[i-denoms[j]]!=INT_MAX))
				res = min(res, dp[i-denoms[j]] + 1);
		}
		dp[i]=res;
	}
	if(dp[n] == INT_MAX)
		return -1;
	return dp[n];
}
