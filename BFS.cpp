#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    queue<Node*>q;
		q.push(this);
		int i,con;
		while(!q.empty())
		{
			Node* fron=q.front();
			q.pop();
			array->push_back(fron->name);
			con=fron->children.size();
			for(i=0;i<con;i++)
				q.push(fron->children[i]);
		}
		return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
