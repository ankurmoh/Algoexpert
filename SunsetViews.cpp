using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	int i,sz=buildings.size(),runningmax;
	vector<int>res;
	if(sz==0)
		return res;
if(direction == "EAST")
{
	runningmax = buildings[sz-1];
	res.push_back(sz-1);
	for(i=sz-2;i>=0;i--)
	{
		if(buildings[i]>runningmax)
			res.push_back(i);
		runningmax=max(runningmax,buildings[i]);
	}
	reverse(res.begin(),res.end());
}
else if(direction == "WEST")
{
	runningmax = buildings[0];
	res.push_back(0);
	for(i=1;i<sz;i++)
	{
		if(buildings[i]>runningmax)
			res.push_back(i);
		runningmax=max(runningmax,buildings[i]);
	}
}
	return res;
}
