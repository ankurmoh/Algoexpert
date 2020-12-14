#include <vector>
using namespace std;

int indexEqualsValue(vector<int> array) {
  int left=0,right=int(array.size()-1),mid,val;
		while(left<=right)
		{
			mid=left + (right-left)/2;
			val = array[mid];
			if(val<mid)
				left=mid+1;
			else if((val == mid) && (mid==0))
				return mid;
			else if((val == mid) && (mid-1>array[mid-1]))
				return mid;
			else
				right=mid-1;
		}
	return -1;
}
