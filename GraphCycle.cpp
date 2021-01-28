#include <vector>
using namespace std;

bool dfs(int x,vector<vector<int>>& graph, vector<int>& color)
{
	color[x]=1;
	int i,sz=graph[x].size(),neigh;
	for(i=0;i<sz;i++)
	{
	neigh = graph[x][i];
	if(color[neigh]==1)
		return true;
	if((color[neigh]==0) && (dfs(neigh,graph,color)))
		return true;
	}
	color[x]=2;
	return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  int i,N=edges.size(),j;
	vector<int>color(N,0);
	vector<vector<int>>graph(N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<edges[i].size();j++)
		{
			graph[i].push_back(edges[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		if((color[i]==0) && (dfs(i,graph,color)))
				return true;
	}
	return false;
}
