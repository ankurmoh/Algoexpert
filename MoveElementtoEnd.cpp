#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int i,sz=array.size(),j=0,con=0;
	if(sz==0)
  	return {};
	for(i=0;i<sz;i++)
	{
		if(array[i]==toMove)
			con++;
		else
			array[j++]=array[i];
	}
	for(i=j;i<sz;i++)
		array[i]=toMove;
	return array;
}
