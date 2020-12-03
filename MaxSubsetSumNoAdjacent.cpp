#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
 int i,sz=array.size();
	if(sz==0)
		return 0;
	if(sz==1)
		return array[0];
	if(sz==2)
		return max(array[0],array[1]);
	vector<int>dp(sz);
	dp[0]=array[0];
	dp[1]=max(dp[0],array[1]);
	for(i=2;i<sz;i++)
		dp[i]=max(array[i] + dp[i-2], dp[i-1]);
	return dp[sz-1];
}
