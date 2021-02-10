#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
sort(redShirtHeights.begin(),redShirtHeights.end());
	sort(blueShirtHeights.begin(),blueShirtHeights.end());
	int i,sz=redShirtHeights.size(),con1=0,con2=0;
	for(i=0;i<sz;i++)
	{
		if(redShirtHeights[i]>blueShirtHeights[i])
			con1++;
		else if(redShirtHeights[i]<blueShirtHeights[i])
			con2++;
		else
			return false;
	}
	if((con1==sz) || (con2==sz))
		return true;
	return false;
}
