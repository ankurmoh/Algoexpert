#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
 unordered_map<int,int>mp;
	int i,sz=array.size();
	vector<int>res;
	for(i=0;i<sz;i++)
	{
		if(mp.find(targetSum-array[i])!=mp.end())
		{
			res.push_back(array[i]);
			res.push_back(targetSum-array[i]);
			return res;
		}
		mp[array[i]]=1;
	}
	return res;
}
