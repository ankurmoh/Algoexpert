#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
vector<vector<int>>res;
	int i,sz=array.size(),cur,j,maxval,ind=0;
	if(sz==0)
		return res;
	vector<int>dp(sz),sequence(sz,-1);
	dp[0]=array[0];
	maxval=dp[0];
	for(i=1;i<sz;i++)
	{
		cur=array[i];
		for(j=0;j<i;j++)
		{
			if((array[i]>array[j]) && (dp[j] + array[i] >cur))
			{
				cur = dp[j]+array[i];
				sequence[i]=j;
			}
		}
		dp[i]=cur;
		if(dp[i]>maxval)
		{
			maxval=dp[i];
			ind=i;
		}
	}
	res.push_back({maxval});
	vector<int>temp;
	while(ind!=-1)
	{
		temp.insert(temp.begin(),array[ind]);
		ind=sequence[ind];
	}
	//reverse(temp.begin(),temp.end());
	res.push_back(temp);
	return res;
}
