using namespace std;

int levenshteinDistance(string str1, string str2) {
  int i,j,len1=str1.length(),len2=str2.length(),add;
	vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
	for(i=1;i<=len1;i++)
		dp[i][0]=i;
	for(j=1;j<=len2;j++)
		dp[0][j]=j;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]!=str2[j-1])
				add=1;
			else
				add=0;
			dp[i][j]=min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1] + add));
		}
	}
	return dp[len1][len2];
}
