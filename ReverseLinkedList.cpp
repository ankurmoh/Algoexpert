using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
	if((head == NULL) || (head->next==NULL))
		return head;
	LinkedList *p = reverseLinkedList(head->next);
	head->next->next=head;
	head->next=NULL;
	return p;
}
