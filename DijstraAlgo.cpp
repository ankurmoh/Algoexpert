#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  unordered_map<int, vector<pair<int,int>>>graph;
	int n=edges.size(),i,sz,j,current,current_d,neigh,weight;
	for(i=0;i<n;i++)
	{
		vector<vector<int>>temp = edges[i];
		sz=temp.size();
		for(j=0;j<sz;j++)
		{
			graph[i].push_back(make_pair(temp[j][0],temp[j][1]));
		}
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>,
					greater<pair<int,int>>>pq;
	pq.push(make_pair(0,start));
	vector<int>dist(n,INT_MAX);
	dist[start]=0;
	while(!pq.empty())
	{
		pair<int,int> fron = pq.top();
		pq.pop();
		current = fron.second;
		current_d = fron.first;
		sz = graph[current].size();
		for(i=0;i<sz;i++)
		{
			neigh = graph[current][i].first;
			weight = graph[current][i].second;
			if((dist[neigh]==INT_MAX) || (dist[neigh]>weight+current_d))
			{
				dist[neigh] = weight+current_d;
				pq.push(make_pair(dist[neigh],neigh));
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(dist[i]==INT_MAX)
			dist[i]=-1;
	}
  return dist;
}
