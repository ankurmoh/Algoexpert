using namespace std;

int longestPeak(vector<int> array) {
  int i=1,sz=array.size(),left,right,maxsz=0,cur,k;
	bool peak;
	if(sz==0)
  	return 0;
	while(i<sz-1)
	{
		peak=false;
		if((array[i]>array[i-1]) && (array[i]>array[i+1]))
		{
			peak=true;
		}
		if(peak==false)
			i++;
		else
		{
			left=i-1;
			right=i+1;
			cur=3;
			k=i;
			while((left>=0) && (array[k]>array[left]))
			{
				k=left;
				left--;
			}
			k=i;
			while((right<sz) && (array[k]>array[right]))
			{
				k=right;
				right++;
			}
			cur=max(cur,right-left-1);
			maxsz=max(maxsz,cur);
			i=right;
		}
	}
	return maxsz;
}
