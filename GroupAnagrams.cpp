#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
  vector<vector<string>>res;
	int i,sz=words.size(),len,j;
	string temp,root;
	if(sz==0)
		return res;
	unordered_map<string,vector<string>>mp;
	vector<int>freq(26);
	for(i=0;i<sz;i++)
	{
		temp = words[i];
		len=temp.length();
		for(j=0;j<26;j++)
			freq[j]=0;
		for(j=0;j<len;j++)
			freq[temp[j]-'a']++;
		root = string(freq.begin(),freq.end());
		mp[root].push_back(temp);
	}
	for(auto it=mp.begin();it!=mp.end();it++)
		res.push_back(it->second);
	return res;
}
