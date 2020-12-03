using namespace std;

// This is the class of the input root. Do not edit it.
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

void preorder(BinaryTree *root,vector<int>& arr,int sum)
{
	if(root == NULL)
		return;
	sum=sum+root->value;
	if((root->left == NULL) && (root->right == NULL))
	{
		arr.push_back(sum);
		return;
	}
	preorder(root->left,arr,sum);
	preorder(root->right,arr,sum);
}
vector<int> branchSums(BinaryTree *root) {
	vector<int>arr;
	if(root==NULL)
		return arr;
  preorder(root,arr,0);
	return arr;
}
