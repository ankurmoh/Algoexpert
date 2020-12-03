#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
	vector<int>res;
	if(array.size()<3)
		return res;
  int f=INT_MIN,s=INT_MIN,t=INT_MIN,i,sz=array.size();
	for(i=0;i<sz;i++)
	{
		if(array[i]>f)
		{
			t=s;
			s=f;
			f=array[i];
		}
		else if((array[i]<=f) && (array[i]>s))
		{
			t=s;
			s=array[i];
		}
		else if((array[i]<=s) && (array[i]>t))
			t=array[i];
	}
	res = {t,s,f};

  return res;
}
