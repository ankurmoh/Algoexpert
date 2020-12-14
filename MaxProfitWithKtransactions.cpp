#include <vector>
#include<bits/stdc++.h>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
  int i,j,sz=prices.size(),maxsofar;
	if((k==0) || (sz==0))
		return 0;
	vector<vector<int>>dp(k+1,vector<int>(sz,0));
	for(i=1;i<=k;i++)
	{
		maxsofar=INT_MIN;
		for(j=1;j<sz;j++)
		{
			maxsofar=max(maxsofar, dp[i-1][j-1] - prices[j-1]);
			dp[i][j]=max(dp[i][j-1], prices[j] + maxsofar);
		}
	}
	return dp[k][sz-1];
}
