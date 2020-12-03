#include <vector>
using namespace std;
int memo(vector<int>& dp,vector<int>& array,int pos)
{
	int i,sz=array.size(),range,neigh,minjump=sz;
	if(pos>=sz-1)
		return 0;
	range = pos+array[pos];
	if(range>=sz-1)
		return 1;
	if(dp[pos]!=-1)
		return dp[pos];
	for(i=pos+1;i<=range;i++)
	{
		neigh = memo(dp,array,i);
		minjump=min(minjump,neigh);
	}
	dp[pos]=1+minjump;
	return dp[pos];
}
int minNumberOfJumps(vector<int> array) {
	int sz=array.size(),i,max_jump_from_here=0,current_ladder_end=0,jump=0;
	// vector<int>dp(sz,-1);
	// dp[sz-1]=0;
	// return memo(dp,array,0);
  for(i=0;i<sz-1;i++)
	{
		max_jump_from_here=max(max_jump_from_here,i+array[i]);
		if(current_ladder_end == i)
		{
			jump++;
			current_ladder_end = max_jump_from_here;
		}
	}
	return jump;
}
