using namespace std;

string smallestSubstringContaining(string bigString, string smallString) {
 unordered_map<char,int>required;
	unordered_map<char,int>window;
	int i,len1=smallString.length(),len2=bigString.length(),
	left=0,right,formed=0,maxlen=INT_MAX,start=-1;
	for(i=0;i<len1;i++)
		required[smallString[i]]++;
	for(right=0;right<len2;right++)
	{
		window[bigString[right]]++;
		if((required.find(bigString[right])!=required.end()) &&
			(required[bigString[right]] == window[bigString[right]]))
		{
			formed++;
		}
		while((formed == required.size()) && (left<=right))
		{
			if(maxlen > right-left+1)
			{
				maxlen=right-left+1;
				start=left;
			}
			window[bigString[left]]--;
			if(window[bigString[left]] == 0)
				window.erase(bigString[left]);
			if((required.find(bigString[left])!=required.end()) &&
			(required[bigString[left]] > window[bigString[left]]))
			{
				formed--;
			}
			left++;
		}
	}
	//cout<<start<<" "<<maxlen;
	if(maxlen == INT_MAX)
		return "";
	return bigString.substr(start,maxlen);
}
