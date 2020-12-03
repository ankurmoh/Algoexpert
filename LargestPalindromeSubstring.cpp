using namespace std;
pair<int,int> extend(string str,int left,int right)
{
	int len=str.length();
	while((left>=0) && (right<len) && (str[left]==str[right]))
	{
		left--;
		right++;
	}
	return make_pair(right-left-1,left+1);
}
string longestPalindromicSubstring(string str) {
 int i,len=str.length(),start=0,max1=1;
	pair<int,int>fron, fron1;
	for(i=0;i<len-1;i++)
	{
		fron = extend(str,i,i);
		fron1 = extend(str,i,i+1);
		if(max1 < fron.first)
		{
			max1 = fron.first;
			start = fron.second;
		}
		if(max1 < fron1.first)
		{
			max1 = fron1.first;
			start = fron1.second;
		}
	}
	return str.substr(start,max1);
}
