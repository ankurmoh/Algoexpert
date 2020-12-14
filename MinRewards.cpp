#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  int i,sz=scores.size(),j,sum=0;
	if(sz==0)
		return 0;
	vector<int>dp(sz,1);
	for(i=1;i<sz;i++)
	{
		if(scores[i]>scores[i-1])
			dp[i]=1+dp[i-1];
		else if(scores[i]<scores[i-1])
		{
			j=i-1;
			while((j>=0) && (scores[j]>scores[j+1]))
			{
				dp[j]=max(dp[j],1+dp[j+1]);
				j--;
			}
		}
	}
	for(i=0;i<sz;i++)
		sum=sum+dp[i];
	return sum;
}

#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
 int i,sz=scores.size(),sum=0;
	if(sz==0)
		return 0;
	vector<int>dp(sz,1);
	for(i=1;i<sz;i++)
	{
		if(scores[i]>scores[i-1])
			dp[i]=1+dp[i-1];
	}
	for(i=sz-2;i>=0;i--)
	{
		if(scores[i]>scores[i+1])
			dp[i]=max(dp[i],1+dp[i+1]);
	}
	for(i=0;i<sz;i++)
		sum=sum+dp[i];
	return sum;
}
