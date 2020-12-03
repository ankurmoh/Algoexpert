class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
bool valid(BST* tree,BST* minNode,BST* maxNode)
{
	if(tree==NULL)
		return true;
	if((minNode!=NULL) && (minNode->value>tree->value))
		return false;
	if((maxNode!=NULL) && (maxNode->value<=tree->value))
		return false;
	return ((valid(tree->left,minNode,tree)) && (valid(tree->right,tree,maxNode)));
}
bool validateBst(BST *tree) {
  if(tree==NULL)
		return true;
	if((tree->left==NULL) && (tree->right==NULL))
		return true;
	return valid(tree,NULL,NULL);
}
