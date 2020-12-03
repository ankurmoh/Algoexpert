using namespace std;

// This is an input class. Do not edit.
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

pair<int,int> get(BinaryTree *tree)
{
	if(tree==NULL)
	{
		return make_pair(0,0);
	}
	if((tree->left==NULL) && (tree->right==NULL))
	{
		return make_pair(0,1);
	}
	pair<int,int>left = get(tree->left);
	pair<int,int>right = get(tree->right);
	int longest_path_thru_root = left.second+right.second;
	int maxdia_so_far = max(left.first,right.first);
	int current_dia = max(maxdia_so_far, longest_path_thru_root);
	int curheight=1+max(left.second,right.second);
	return make_pair(current_dia,curheight);
}
int binaryTreeDiameter(BinaryTree *tree) {
  return get(tree).first;
}
