#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(),arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
	int i=0,j=0,len1=arrayOne.size(),len2=arrayTwo.size(),maxdiff=INT_MAX,val1=-1,val2=-1;
	while((i<len1) && (j<len2))
	{
		if(maxdiff > abs(arrayOne[i] - arrayTwo[j]))
		{
			maxdiff = abs(arrayOne[i] - arrayTwo[j]);
			val1=arrayOne[i];
			val2=arrayTwo[j];
		}
		if(arrayOne[i] == arrayTwo[j])
		{
			break;
		}
		else if(arrayOne[i]>arrayTwo[j])
			j++;
		else
			i++;
	}
	vector<int>res = {val1,val2};
  return res;
}
