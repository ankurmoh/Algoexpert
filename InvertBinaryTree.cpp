#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
  queue<BinaryTree*>q;
	if(tree==NULL)
		return;
	q.push(tree);
	int i,con;
	BinaryTree *fron,*left;
	while(!q.empty())
	{
		con = q.size();
		for(i=0;i<con;i++)
		{
			fron=q.front();
			q.pop();
			left=fron->left;
			fron->left=fron->right;
			fron->right=left;
			if(fron->left)
				q.push(fron->left);
			if(fron->right)
				q.push(fron->right);
		}
	}
}
