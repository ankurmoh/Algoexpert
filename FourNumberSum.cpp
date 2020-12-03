#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	int i,j,k,l,sz=array.size(),sum;
	vector<vector<int>>res;
	sort(array.begin(),array.end());
	if(sz<4)
		return res;
	if((sz == 4) && ((4*array[0]>targetSum) || (4*array[3]<targetSum)))
		return res;
  set<vector<int>>st;
	for(i=0;i<=sz-4;i++)
	{
		for(j=i+1;j<=sz-3;j++)
		{
			k=j+1;
			l=sz-1;
			while(k<l)
			{
				sum = array[i]+array[j]+array[k]+array[l];
				if(sum == targetSum)
				{
					vector<int>temp = {array[i],array[j],array[k],array[l]};
					if(!st.count(temp))
					{
						st.insert(temp);
						res.push_back(temp);
					}
					k++;
					l--;
				}
				else if(sum<targetSum)
					k++;
				else
					l--;
			}
		}
	}
  return res;
}
