#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
 int left=0,right=array.size(),mid;
	while(left<right)
	{
		mid = left + (right-left)/2;
		if(array[mid]<target)
			left=mid+1;
		else
			right=mid;
	}
	if(array[left]==target)
		return left;
	return -1;
}
