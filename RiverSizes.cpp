#include <vector>
using namespace std;
vector<vector<int>>dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int dfs(vector<vector<int>>& matrix,vector<vector<int>>& visited,int x,int y)
{
	visited[x][y]=1;
	int con = 1;
	int i,newx,newy;
	for(i=0;i<4;i++)
	{
		newx = x + dir[i][0];
		newy = y + dir[i][1];
		if((newx>=0)&&(newx<matrix.size())&&(newy>=0)&&(newy<matrix[0].size())&&(visited[newx][newy]==0)&&(matrix[newx][newy]==1))
		{
			con = con + dfs(matrix,visited,newx,newy);
		}
	}
	return con;
}
vector<int> riverSizes(vector<vector<int>> matrix) {
 int i,j,sz1=matrix.size(),sz2;
	if(sz1==0)
		return {};
	vector<int>res;
	sz2=matrix[0].size();
	vector<vector<int>>visited(sz1,vector<int>(sz2,0));
	for(i=0;i<sz1;i++)
	{
		for(j=0;j<sz2;j++)
		{
			if((visited[i][j]==0) && (matrix[i][j]==1))
			{
				res.push_back(dfs(matrix,visited,i,j));
			}
		}
	}
	return res;
}
