#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  // Write your code here.
  int i,j,len1=str1.length(),len2=str2.length(),k;
	vector<vector<int>>dp(len1+1,vector<int>(len2+1));
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			if((i==0) || (j==0))
				dp[i][j]=0;
			else if(str1[i-1] == str2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	vector<char>ans(dp[len1][len2]);
	i=len1 ;j=len2,k = dp[len1][len2]-1;
	while((i>0) && (j>0))
	{
		if(dp[i][j]==dp[i-1][j])
			i--;
		else if(dp[i][j] == dp[i][j-1])
			j--;
		else if(dp[i][j] == 1 + dp[i-1][j-1])
		{
			//ans.insert(ans.begin(),str1[i-1]);
			ans[k] = str2[j-1];
			i--;j--;
			k--;
		}
	}
	return ans;
}
