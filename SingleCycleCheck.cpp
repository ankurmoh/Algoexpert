using namespace std;

int next(int x,vector<int>& array)
{
	int cur = x + array[x],sz=array.size();
	cur=cur%sz;
	if(cur<0)
		cur=cur+sz;
	return cur;
}
bool hasSingleCycle(vector<int> array) {
int i,sz=array.size(),jumps=0,start=0;
	if(sz==0)
		return false;
	while(jumps<sz)
	{
		start=next(start,array);
		jumps++;
		if((start == 0) && (jumps>0) && (jumps<sz))
			return false;
	}
	return (start==0);
}
