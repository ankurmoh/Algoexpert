#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  int i,j,sz1=matrix.size(),sz2;
	if(sz1==0)
		return {-1,-1};
	sz2=matrix[0].size();
	i=0;j=sz2-1;
	while((i<sz1) && (j>=0))
	{
		if(matrix[i][j]==target)
		{
			vector<int>res = {i,j};
			return res;
		}
		if(matrix[i][j]>target)
			j--;
		else
			i++;
	}
  return {-1,-1};
}
