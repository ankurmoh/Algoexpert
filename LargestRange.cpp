#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  int i,sz=array.size(),cur,left,right,maxlen=0;
	if(sz==0)
  	return {};
	vector<int>res;
	unordered_map<int,int>mp;
	for(i=0;i<sz;i++)
		mp[array[i]]++;
	for(i=0;i<sz;i++)
	{
		if((mp.find(array[i]) == mp.end()))
			continue;
		mp[array[i]]--;
		if(mp[array[i]]==0)
			mp.erase(array[i]);
		cur=1;
		left=array[i]-1;
		right=array[i]+1;
		while(mp.find(left)!=mp.end())
		{
			mp[left]--;
			if(mp[left]==0)
				mp.erase(left);
			cur++;
			left--;
		}
		while(mp.find(right)!=mp.end())
		{
			mp[right]--;
			if(mp[right]==0)
				mp.erase(right);
			cur++;
			right++;
		}
		if(cur>maxlen)
		{
			maxlen=cur;
			res = {left+1,right-1};
		}
	}
	return res;
}
