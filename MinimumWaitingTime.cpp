using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(),queries.end());
	int i,sz=queries.size(),cur=queries[0],cur1=cur;
	if(sz<=1)
		return 0;
	for(i=1;i<sz-1;i++)
	{
		cur=cur+queries[i];
		cur1=cur1+cur;
	}
	return cur1;
}
