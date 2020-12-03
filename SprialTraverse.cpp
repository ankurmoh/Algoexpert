using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
 	int startrow,startcolumn,endrow,endcolumn,sz=array.size(),
	sz1=array[0].size(),dir=0,i;
	if((sz==0) || (sz1==0))
  	return {};
	vector<int>res;
	startrow=0;startcolumn=0;endrow=sz-1;endcolumn=sz1-1;
	while((startrow<=endrow) && (startcolumn<=endcolumn))
	{
		switch(dir)
		{
			case 0:
				{
				for(i=startcolumn;i<=endcolumn;i++)
					res.push_back(array[startrow][i]);
				startrow++;
				break;
				}
			case 1:
				{
					for(i=startrow;i<=endrow;i++)
						res.push_back(array[i][endcolumn]);
					endcolumn--;
					break;
				}
			case 2:
				{
					for(i=endcolumn;i>=startcolumn;i--)
						res.push_back(array[endrow][i]);
					endrow--;
					break;
				}
			case 3:
				{
					for(i=endrow;i>=startrow;i--)
						res.push_back(array[i][startcolumn]);
					startcolumn++;
					break;
				}
		}
		dir=(dir+1)%4;
	}
	return res;
}
