#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	set<vector<int>>st;
	vector<vector<int>>res;
	sort(array.begin(),array.end());
	int i,j,k,sz=array.size();
	for(i=0;i<=sz-3;i++)
	{
		j=i+1;
		k=sz-1;
		while(j<k)
		{
			if(array[i]+array[j]+array[k] == targetSum)
			{
				vector<int>temp = {array[i],array[j],array[k]};
				if(st.count(temp) == 0)
				{
					st.insert(temp);
					res.push_back(temp);
				}
				j++;
				k--;
			}
			else if(array[i]+array[j]+array[k] < targetSum)
				j++;
			else
				k--;
		}
	}
	sort(res.begin(),res.end());
  return res;
}
