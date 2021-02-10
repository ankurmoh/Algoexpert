#include<bits/stdc++.h>
using namespace std;

void reverse(string& str,int low,int high)
{
	while(low<high)
	{
		char temp = str[low];
		str[low] = str[high];
		str[high] = temp;
		low++;
		high--;
	}
}
string reverseWordsInString(string str) {
  int i=0,len=str.length(),j;
	string temp="";
	while(i<len)
	{
		//cout<<i<<" ";
		if(str[i]!=' ')
		{
			j=i;
			//temp="";
			while((j<len) && (str[j]!=' '))
			{
				//temp=temp + str[j];
				j++;
			}
			//cout<<i<<j<<" ";
			reverse(str,i,j-1);
			//cout<<str<<endl;
			i=j;
		}
		else if(str[i]==' ')
			i++;
	}
	reverse(str,0,len-1);
	return str;
}
