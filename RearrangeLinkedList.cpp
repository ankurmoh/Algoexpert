using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};
pair<LinkedList*,LinkedList*> link(LinkedList *head1,LinkedList *tail1,
																	LinkedList *head2,LinkedList *tail2)
{
	if(tail1!=NULL)
		tail1->next=head2;
	LinkedList* tail=NULL;
	if(tail2==NULL)
		tail=tail1;
	else
		tail=tail2;

	LinkedList* head=NULL;
	if(head1==NULL)
		head=head2;
	else
		head = head1;
	return make_pair(head,tail);
}
pair<LinkedList*, LinkedList*> create(LinkedList* head,LinkedList* tail,
																			LinkedList* node)
{
	LinkedList* newhead=head;
	LinkedList* newtail=node;

	if(newhead == NULL)
		newhead = node;
	if(tail!=NULL)
		tail->next=newtail;
	return make_pair(newhead,newtail);
}
LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
	LinkedList* lessthanHead=NULL;
	LinkedList* lessthanTail=NULL;
	LinkedList* equalHead=NULL;
	LinkedList* equalTail=NULL;
	LinkedList* morethanHead=NULL;
	LinkedList* morethanTail=NULL;
	LinkedList* ptr = head;
	LinkedList* prev=NULL;
	while(ptr!=NULL)
	{
		if(ptr->value<k)
		{
			pair<LinkedList*,LinkedList*> less=create(lessthanHead,lessthanTail,ptr);
			lessthanHead = less.first;
			lessthanTail = less.second;
		}
		else if(ptr->value == k)
		{
			pair<LinkedList*,LinkedList*> equal = create(equalHead,equalTail,ptr);
			equalHead = equal.first;
			equalTail = equal.second;
		}
		else
		{
			pair<LinkedList*,LinkedList*> more=create(morethanHead,morethanTail,ptr);
			morethanHead = more.first;
			morethanTail = more.second;
		}
		prev = ptr;
		ptr = ptr->next;
		prev->next = NULL;
	}
	pair<LinkedList*,LinkedList*>first = link(lessthanHead,lessthanTail,
																						equalHead,equalTail);
	pair<LinkedList*,LinkedList*>second = link(first.first,first.second,
																						morethanHead,morethanTail);
	return second.first;
}
