using namespace std;
struct comp
{
	bool operator()(const vector<int>& a,const vector<int>& b)
	{
		if(a[0]!=b[0])
			return a[0]>b[0];
		return a[1]>b[1];
	}
};
vector<int> mergeSortedArrays(vector<vector<int>> arrays) {
vector<int>res;
	priority_queue<vector<int>, vector<vector<int>>, comp>pq;
	int i,j,sz=arrays.size(),newpos,index;
	if(sz==0)
		return res;
	for(i=0;i<sz;i++)
	{
		vector<int>temp = arrays[i];
		pq.push({temp[0],i,0});
	}
	while(!pq.empty())
	{
		vector<int>temp = pq.top();
		pq.pop();
		res.push_back(temp[0]);
		newpos = temp[2]+1;
		index = temp[1];
		if(newpos<arrays[index].size())
		{
			pq.push({arrays[index][newpos],index,newpos});
		}
	}
	return res;
}
