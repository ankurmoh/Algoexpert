#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  int i,sz=array.size();
	if(sz == 0)
  	return {};
	vector<int>left(sz), right(sz), res(sz);
	left[0]=array[0];
	for(i=1;i<sz;i++)
		left[i]=left[i-1]*array[i];
	right[sz-1]=array[sz-1];
	for(i=sz-2;i>=0;i--)
		right[i]=array[i]*right[i+1];
	res[0]=right[1];
	res[sz-1]=left[sz-2];
	for(i=1;i<=sz-2;i++)
		res[i]=left[i-1]*right[i+1];
	return res;
}
