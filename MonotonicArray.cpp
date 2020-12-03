using namespace std;

bool isMonotonic(vector<int> array) {
  int i,con1=0,con2=0,sz=array.size();
	if(sz<=1)
		return true;
	for(i=0;i<sz-1;i++)
	{
		if(array[i]>=array[i+1])
			con1++;
		if(array[i]<=array[i+1])
			con2++;
	}
	if((con1==sz-1) || (con2==sz-1))
		return true;
  return false;
}
