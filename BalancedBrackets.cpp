#include<bits/stdc++.h>

using namespace std;

bool balancedBrackets(string str) {
  stack<char>st;
	int i,len=str.length();
	for(i=0;i<len;i++)
	{
		if((str[i] == '(') || (str[i]=='[') || (str[i] == '{'))
			st.push(str[i]);
		else if(str[i]==']')
		{
			if(st.empty())
				return false;
			if(st.top()!='[')
				return false;
			st.pop();
		}
		else if(str[i]==')')
		{
			if(st.empty())
				return false;
			if(st.top()!='(')
				return false;
			st.pop();
		}
		else if(str[i]=='}')
		{
			if(st.empty())
				return false;
			if(st.top()!='{')
				return false;
			st.pop();
		}
	}
	if(!st.empty())
  	return false;
	return true;
}
