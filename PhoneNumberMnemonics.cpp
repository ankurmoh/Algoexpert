#include <vector>
using namespace std;


vector<string> phoneNumberMnemonics(string phoneNumber) {
 unordered_map<char,string>mp;
	mp['0']="0";
	mp['1']="1";
	mp['2']="abc";
	mp['3']="def";
	mp['4']="ghi";
	mp['5']="jkl";
	mp['6']="mno";
	mp['7']="pqrs";
	mp['8']="tuv";
	mp['9']="wxyz";
	int i,len=phoneNumber.length(),j,k;
	vector<string>res;
	res.push_back("");
	string t;
	for(i=0;i<len;i++)
	{
	char ch = phoneNumber[i];
	t = mp[ch];
		vector<string>temp;
		for(j=0;j<t.length();j++)
		{
			for(k=0;k<res.size();k++)
			{
				temp.push_back(res[k]+t[j]);
			}
		}
		res=temp;
	}
	return res;
}
