using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  LinkedList *head1 = linkedListOne;
	LinkedList *head2 = linkedListTwo;
	if((head1==NULL) && (head2==NULL))
  	return nullptr;
	if((head1==NULL) && (head2!=NULL))
  	return head2;
	if((head1!=NULL) && (head2==NULL))
  	return head1;
	LinkedList *dummy = new LinkedList(0);
	LinkedList *current = dummy;
	int sum=0,carry=0;
	while((head1!=NULL) || (head2!=NULL) || (carry>0))
	{
		sum=0;
		if(head1!=NULL)
		{
			sum=sum+head1->value;
			head1=head1->next;
		}
		if(head2!=NULL)
		{
			sum=sum+head2->value;
			head2=head2->next;
		}
		sum=sum+carry;
		//LinkedList *dummy = new LinkedList(sum%10);
		current->next = new LinkedList(sum%10);
		carry = sum/10;
		current = current->next;
		//current = dummy;
	}
	return dummy->next;
}
