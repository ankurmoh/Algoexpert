#include <vector>

using namespace std;

bool boundary(int x,int y,int nr,int nc)
{
	if((x<0) || (y<0) || (x>nr) || (y>nc))
		return true;
	return false;
}
vector<int> zigzagTraverse(vector<vector<int>> array) {
  if(array.size()==0)
  	return {};
	vector<int>res;
	bool down=true;
	int row=0,col=0,numrows=array.size()-1,numcolumns=array[0].size()-1;
	while(!boundary(row,col,numrows,numcolumns))
	{
		res.push_back(array[row][col]);
		if(down == true)
		{
			if((col==0) || (row == numrows))
			{
				down=false;
				if(row == numrows)
					col++;
				else if(col == 0)
					row++;
			}
			else
			{
				col--;
				row++;
			}
		}
		else if(down == false)
		{
			if((row == 0) || (col == numcolumns))
			{
				down=true;
				if(col == numcolumns)
					row++;
				else if(row == 0)
					col++;
			}
			else
			{
				col++;
				row--;
			}
		}
	}
	return res;
}
