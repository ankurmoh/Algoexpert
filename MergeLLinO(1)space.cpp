#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
  if((headOne==NULL) && (headTwo==NULL))
  	return NULL;
	else if((headOne==NULL) && (headTwo!=NULL))
		return headTwo;
	else if((headOne!=NULL) && (headTwo==NULL))
		return headOne;
	LinkedList* p1=headOne;
	LinkedList* p2=headTwo;
	LinkedList* prev=NULL;
	while((p1!=NULL) && (p2!=NULL))
	{
		if(p1->value<=p2->value)
		{
			prev=p1;
			p1=p1->next;
		}
		else
		{
			if(prev==NULL)
			{
				prev=p2;
				p2=p2->next;
				prev->next=p1;
			}
			else if(prev!=NULL)
			{
				prev->next=p2;
				prev=p2;
				p2=p2->next;
				prev->next=p1;
			}
		}
	}
	if(p1==NULL)
		prev->next=p2;
	return (headOne->value<=headTwo->value)? headOne:headTwo;
}
