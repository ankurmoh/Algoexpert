#include <vector>
using namespace std;
vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool dfs(int x,int y,vector<vector<char>>& board,string temp,int pos)
{
	if(pos == temp.length())
		return true;
	int i,j,sz1=board.size(),sz2=board[0].size(),newx,newy;
	if((x<0)||(x>=sz1)||(y<0)||(y>=sz2)||(board[x][y]!=temp[pos]))
		return false;
	char ch = board[x][y];
	board[x][y]='*';
	bool res=false;
	for(i=0;i<8;i++)
	{
		newx = x + dir[i][0];
		newy = y + dir[i][1];
		res = dfs(newx,newy,board,temp,pos+1) || res;
	}
	board[x][y]=ch;
	return res;
}
bool find(vector<vector<char>>& board, string temp)
{
	int i,j,sz1=board.size(),sz2=board[0].size();
	bool res=false;
	for(i=0;i<sz1;i++)
	{
		for(j=0;j<sz2;j++)
		{
			if(board[i][j]==temp[0])
				res = dfs(i,j,board,temp,0) || res;
		}
	}
	return res;
}
vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
  int i,sz=words.size();
	vector<string>res;
	for(i=0;i<sz;i++)
	{
		if(find(board,words[i]))
			res.push_back(words[i]);
	}
	return res;
}
