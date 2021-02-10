#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
 sort(coins.begin(),coins.end());
	int i,sz=coins.size(),mini;
	if(sz==0)
		return 1;
	if(coins[0]>1)
		return 1 ;
	mini = coins[0];
	for(i=1;i<sz;i++)
	{
		if(coins[i]>mini+1)
			return mini+1;
		mini = mini + coins[i];
	}
	return mini+1;
}
