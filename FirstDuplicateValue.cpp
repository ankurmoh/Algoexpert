#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) {
	int i,sz=array.size(),index,cur;
	for(i=0;i<sz;i++)
	{
		cur = array[i];
		index = abs(cur) - 1;
		if(array[index] <0)
			return abs(cur);
		array[index] = -array[index];
	}


	return -1; }
