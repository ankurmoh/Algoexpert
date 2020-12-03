using namespace std;

int getNthFib(int n) {
  vector<int>dp(n+1,0);
	dp[2]=1;
	int a=0,b=1,c;
	// for(int i=3;i<=n;i++)
	// 	dp[i]=dp[i-1]+dp[i-2];
	// return dp[n];
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	for(int i=3;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}
