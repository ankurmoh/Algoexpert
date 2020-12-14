#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  if((head == NULL) || (head->next == NULL))
		return;
	int i,len=0;
	LinkedList *ptr = head;
	while(ptr!=NULL)
	{
		len++;
		ptr=ptr->next;
	}
	if(k == len)
	{
		head->value = head->next->value;
		head->next = head->next->next;
		//cout<<head->value;
		return;
	}
	ptr = head;
	for(i=1;i<=len-k-1;i++)
		ptr=ptr->next;
	ptr->next=ptr->next->next;
	//return head;
}
