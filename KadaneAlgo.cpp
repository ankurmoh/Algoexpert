#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  int i,sz=array.size(),maxsofar=array[0],maxres=array[0];
	for(i=1;i<sz;i++)
	{
		maxsofar=max(maxsofar+array[i],array[i]);
		maxres=max(maxres,maxsofar);
	}
	return maxres;
}
