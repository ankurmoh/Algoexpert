#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string,int>mp;
	int i,sz=competitions.size(),maxi=0;
	string home,away;
	for(i=0;i<sz;i++)
	{
		home = competitions[i][0];
		away = competitions[i][1];
		if(results[i]==1)
		{
			mp[home]++;
			maxi=max(maxi,mp[home]);
		}
		else
		{
			mp[away]++;
			maxi=max(maxi,mp[away]);
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	{
		if(it->second==maxi)
			return it->first;
	}
  return "";
}
