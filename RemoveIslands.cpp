#include <vector>
using namespace std;

vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(queue<pair<int,int>>& q, vector<vector<int>>& visited,
				 vector<vector<int>>& matrix)
{
	int i,sz,k,x,y;
	while(!q.empty())
	{
		sz=q.size();
		for(i=0;i<sz;i++)
		{
			pair<int,int> fron = q.front();
			q.pop();
			for(k=0;k<4;k++)
			{
				x = fron.first + dir[k][0];
				y = fron.second + dir[k][1];
				if((x>=0) && (x<matrix.size()) && (y>=0) && (y<matrix[0].size())
					&& (visited[x][y]==0) && (matrix[x][y]==1))
				{
					visited[x][y] = 1;
					matrix[x][y] = 2;
					q.push(make_pair(x,y));
				}
			}
		}
	}
}
vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  int i,j,n=matrix.size(),m=matrix[0].size();
	vector<vector<int>>visited(n,vector<int>(m,0));
	queue<pair<int,int>>q;
	for(i=0;i<n;i++)
	{
		if((visited[i][0]==0) && (matrix[i][0]==1))
		{
			visited[i][0]=1;
			q.push(make_pair(i,0));
			matrix[i][0]=2;
		}
		if((visited[i][m-1]==0) && (matrix[i][m-1]==1))
		{
			visited[i][m-1]=1;
			q.push(make_pair(i,m-1));
			matrix[i][m-1]=2;
		}
	}
	for(i=0;i<m;i++)
	{
		if((visited[0][i]==0) && (matrix[0][i]==1))
		{
			visited[0][i]=1;
			q.push(make_pair(0,i));
			matrix[0][i]=2;
		}
		if((visited[n-1][i]==0) && (matrix[n-1][i]==1))
		{
			visited[n-1][i]=1;
			q.push(make_pair(n-1,i));
			matrix[n-1][i]=2;
		}
	}
	bfs(q,visited,matrix);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]==2)
				matrix[i][j]=1;
			else
				matrix[i][j]=0;
		}
	}
  return matrix;
}
