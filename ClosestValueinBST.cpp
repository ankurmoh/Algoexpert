class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  if(tree==NULL)
		return 0;
	int maxdiff=INT_MAX,val1=-1;
	while(tree!=NULL)
	{
		if(maxdiff > abs(tree->value - target))
		{
			maxdiff = abs(tree->value - target);
			val1 = tree->value;
		}
		if(tree->value > target)
			tree=tree->left;
		else if(tree->value < target)
			tree=tree->right;
		else
			return tree->value;
	}
	return val1;
  //return -1;
}
