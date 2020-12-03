using namespace std;

string longestSubstringWithoutDuplication(string str) {
 int left=0,right,len=str.length(),right1=-1,left1=-1,maxlen=0;
	unordered_set<char>st;
	for(right=0;right<len;right++)
	{
		while(st.count(str[right])>0)
		{
			st.erase(str[left]);
			left++;
		}
		st.insert(str[right]);
		if(maxlen<right-left+1)
		{
			maxlen = right-left+1;
			right1=right;
			left1=left;
		}
	}
	return str.substr(left1,maxlen);
}
