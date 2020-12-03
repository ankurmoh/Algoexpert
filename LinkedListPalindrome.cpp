using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList* reverse(LinkedList *cur)
{
	LinkedList *prev=NULL, *next = NULL;
	while(cur!=NULL)
	{
		next = cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	return prev;
}
bool linkedListPalindrome(LinkedList *head) {
  if((head == NULL) || (head->next==NULL))
		return true;
	LinkedList *slow=head, *fast=head;
	while((fast->next) && (fast->next->next))
	{
		slow = slow->next;
		fast=fast->next->next;
	}
	LinkedList *newlist = slow->next;
	newlist = reverse(newlist);
	while((head!=slow->next) && (newlist!=NULL))
	{
		if(head->value != newlist->value)
			return false;
		head=head->next;
		newlist=newlist->next;
	}
	// if((head!=slow->next) || (newlist!=NULL))
	// 	return false;
  return true;
}
