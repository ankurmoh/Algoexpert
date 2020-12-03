using namespace std;

bool isPalindrome(string str) {
  int i,len=str.length(),j;
	for(i=0,j=len-1;i<=j;i++,j--)
	{
		if(str[i]!=str[j])
			return false;
	}
  return true;
}
