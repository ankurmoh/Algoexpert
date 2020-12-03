using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};
int nodeDepths(BinaryTree *root) {
	if(root == NULL)
		return 0;
	if((root->left == NULL) && (root->right == NULL))
		return 0;
	int i,con,sum=0;
	queue<BinaryTree*>q;
	q.push(root);
	unordered_map<BinaryTree*,int>mp;
	mp[root]=0;
	BinaryTree *fron;
	while(!q.empty())
	{
		con=q.size();
		for(i=0;i<con;i++)
		{
			fron=q.front();
			q.pop();
			if(fron->left)
			{
				mp[fron->left] = mp[fron]+1;
				q.push(fron->left);
			}
			if(fron->right)
			{
				mp[fron->right] = mp[fron]+1;
				q.push(fron->right);
			}
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
		sum=sum + it->second;
	return sum;
}
