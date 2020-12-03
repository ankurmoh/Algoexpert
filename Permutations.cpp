#include <vector>
using namespace std;
void permute(vector<int>& array,int begin,vector<vector<int>>& res)
{
	if(begin>array.size())
		return;
	if(begin == array.size())
	{
		res.push_back(array);
		return;
	}
	int i,sz=array.size();
	for(i=begin;i<sz;i++)
	{
		swap(array[begin],array[i]);
		permute(array,begin+1,res);
		swap(array[begin],array[i]);
	}
}
vector<vector<int>> getPermutations(vector<int> array) {
  int i,sz=array.size();
	vector<vector<int>>res;
	if(sz==0)
		return res;
	permute(array,0,res);
	return res;
}
