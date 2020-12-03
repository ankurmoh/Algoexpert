#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  int i,j,sz=denoms.size(),x,y;
	//vector<vector<int>>dp(sz,vector<int>(n+1,0));
	vector<int>dp(n+1,0);
	dp[0]=1;
	// for(i=0;i<sz;i++)
	// 	dp[i][0]=1;
	// for(i=1;i<=n;i++)
	// 	dp[0][i]=0;
	for(i=0;i<sz;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j>=denoms[i])
				dp[j]=dp[j]+dp[j-denoms[i]];
			// x=(i>0)? dp[i-1][j] : 0;
			// y = (j>=denoms[i])? dp[i][j-denoms[i]]:0;
			// dp[i][j]=x+y;
		}
	}
	return dp[n];
}
