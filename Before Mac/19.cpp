#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head,int n)
{
	ListNode* p=head;
	ListNode* tmp;
	int length=1,i;
	while(p->next!=NULL)
	{
		p=p->next;
		length++;
	}
	p=head;
	if(length==n)
	{
		head=head->next;
		return head;
	}
	for(i=1;i<length-n;i++)
		p=p->next;
	if(p->next!=NULL)
	{
		tmp=p->next->next;
		p->next=tmp;
	}
	return head;
}
void InsertList(ListNode* head,int x)
{
	ListNode *p=head;
	while(p->next!=NULL)
		p=p->next;
	ListNode *t=(ListNode*)malloc(sizeof(ListNode));
	t->next=NULL;
	t->val=x;
	p->next=t;
}
void ShowList(ListNode* head)
{
	ListNode* p=head;
	while(p!=NULL)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
}
int main()
{
	ListNode *head=(ListNode*)malloc(sizeof(ListNode));
	head->val=1;
	head->next=NULL;
	InsertList(head,2);
	InsertList(head,3);
	InsertList(head,4);
	InsertList(head,5);
	cout<<"before function:";
	ShowList(head);
	head=removeNthFromEnd(head,3);
	//cout<<head->val<<endl;
	cout<<endl<<"after function :";
	ShowList(head);
	return 0;
}
