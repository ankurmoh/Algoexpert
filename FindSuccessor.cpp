using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void traverse(BinaryTree* root, vector<BinaryTree*>& inorder)
{
	if(root==NULL)
		return;
	traverse(root->left,inorder);
	inorder.push_back(root);
	traverse(root->right,inorder);
}
BinaryTree* min_node(BinaryTree* root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  if((tree==NULL) || (node==NULL))
			return NULL;
	// vector<BinaryTree*>inorder;
	// traverse(tree,inorder);
	// int i,sz=inorder.size();
	// for(i=0;i<sz;i++)
	// {
	// 	if((inorder[i] == node) && (i+1 <sz))
	// 		return inorder[i+1];
	// }
	// return NULL;
	if(node->right)
		return min_node(node->right);
	BinaryTree* p = node->parent;
	while((p!=NULL) && (p->right == node))
	{
		node = p;
		p = p->parent;
	}
	return p;
}
