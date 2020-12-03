#include <vector>
using namespace std;

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
int i,n=jobs.size(),j,con,sz,from,to,neigh,fron;
	unordered_map<int,int>indegree;
	for(i=0;i<n;i++)
		indegree[jobs[i]]=0;
	vector<vector<int>>graph(n+1);
	sz=deps.size();
	for(i=0;i<sz;i++)
	{
		from = deps[i][0];
		to = deps[i][1];
		graph[from].push_back(to);
		indegree[to]++;
	}
	queue<int>q;
	for(auto it=indegree.begin();it!=indegree.end();it++)
	{
		if(it->second==0)
			q.push(it->first);
	}
	vector<int>res;
	from=0;
	while(!q.empty())
	{
		con=q.size();
		for(i=0;i<con;i++)
		{
			fron=q.front();
			q.pop();
			res.push_back(fron);
			from++;
			sz=graph[fron].size();
			for(j=0;j<sz;j++)
			{
				neigh = graph[fron][j];
				indegree[neigh]--;
				if(indegree[neigh]==0)
					q.push(neigh);
			}
		}
	}
	if(from == n)
		return res;
	return vector<int>();
}
