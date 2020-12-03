#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  if((arrayOne.size()==0) && (arrayTwo.size()==0))
		return true;
	if(arrayOne.size()!=arrayTwo.size())
		return false;
	if(arrayOne[0]!=arrayTwo[0])
  	return false;
	int i,sz=arrayOne.size();
	vector<int>left1,left2,right1,right2;
	for(i=1;i<sz;i++)
	{
		if(arrayOne[i]<arrayOne[0])
			left1.push_back(arrayOne[i]);
		else if(arrayOne[i]>=arrayOne[0])
			right1.push_back(arrayOne[i]);
		if(arrayTwo[i]<arrayTwo[0])
			left2.push_back(arrayTwo[i]);
		else if(arrayTwo[i]>=arrayTwo[0])
			right2.push_back(arrayTwo[i]);
	}
	return ((sameBsts(left1,left2)) && (sameBsts(right1,right2)));
}
