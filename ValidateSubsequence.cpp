using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int i,j=0,len1=array.size(),len2=sequence.size();
	for(i=0;i<len1;i++)
	{
		if(array[i]==sequence[j])
			j++;
	}
	return j==len2;
}
