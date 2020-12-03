using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == NULL) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == NULL) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};
BST *create(vector<int>& array,int start,int end)
{
	if(start>end)
		return NULL;
	int mid = start + (end-start)/2;
	BST *root = new BST(array[mid]);
	if(start == end)
		return root;
	root->left = create(array,start,mid-1);
	root->right = create(array,mid+1,end);
	return root;
}
BST *minHeightBst(vector<int> array) {
  return create(array,0,array.size()-1);
}
