using namespace std;

string runLengthEncoding(string str) {
 int i,len=str.length(),con,j,div,mod,k;
	string res="";
	char current;
	for(i=0;i<len;)
	{
		current = str[i];
		con=1;
		j=i+1;
		while((j<len) && (str[j]==current))
		{
			con++;
			j++;
		}
		if(con<=9)
		{
			res=res + to_string(con) + current;
		}
		else if(con>9)
		{
			div=con/9;
			mod = con%9;
			for(k=0;k<div;k++)
				res = res + to_string(9) + current;
			if(mod>0)
				res = res + to_string(mod) + current;
		}
		i=j;
	}
	return res;
}
