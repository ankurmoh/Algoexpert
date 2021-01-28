#include <vector>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	vector<pair<int,int>>index;
	vector<vector<int>>res;
	int i,sz=tasks.size(),j;
	for(i=0;i<sz;i++)
	{
	index.push_back(make_pair(tasks[i],i));
	}
	sort(index.begin(),index.end());
	for(i=0,j=sz-1;i<j;i++,j--)
	{
		res.push_back({index[i].second,index[j].second});
	}
	return res;
}
