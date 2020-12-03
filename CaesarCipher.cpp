using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  string temp="";
	int i,len=str.length(),val;
	for(i=0;i<len;i++)
	{
		char ch = str[i];
		val = ch-'a';
		val = val + key;
		val = val%26;
		temp = temp + char(val+'a');
	}
	return temp;
}
