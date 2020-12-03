#include <vector>
using namespace std;
void permute(vector<int>& array,vector<int>& temp,vector<vector<int>>& res,int pos)
{
	res.push_back(temp);
	int i,sz=array.size();
	for(i=pos;i<sz;i++)
	{
		temp.push_back(array[i]);
		permute(array,temp,res,i+1);
		temp.pop_back();
	}
}
vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>>res;
	vector<int>temp;
	permute(array,temp,res,0);
	return res;
}
