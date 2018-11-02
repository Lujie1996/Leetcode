#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
}; 
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
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
	ListNode* p=l1;
	ListNode* q=l2;
	ListNode* t;
	ListNode* result;
	ListNode* l;
	result=(ListNode*)malloc(sizeof(ListNode));
	result->next=NULL;
	l=result;
	while(p!=NULL||q!=NULL)
	{
		t=(ListNode*)malloc(sizeof(ListNode));
		if(p!=NULL&&q!=NULL)
		{
			if(p->val<q->val)
			{
				t->val=p->val;
				t->next=NULL;
				p=p->next;
			}
			else
			{
				t->val=q->val;
				t->next=NULL;
				q=q->next;
			}
		}
		else if(p==NULL)
		{
			t->val=q->val;
			t->next=NULL;
			q=q->next;
		}
		else
		{
			t->val=p->val;
			t->next=NULL;
			p=p->next;
		}
		l->next=t;
		l=l->next;
	}
	result=result->next;
	return result;
}
int main()
{
	ListNode *head1=(ListNode*)malloc(sizeof(ListNode));
	head1->val=1;
	head1->next=NULL;
	InsertList(head1,3);
	InsertList(head1,5);
	InsertList(head1,7);
	InsertList(head1,9);
	ListNode *head2=(ListNode*)malloc(sizeof(ListNode));
	head2->val=0;
	head2->next=NULL;
	InsertList(head2,2);
	InsertList(head2,4);
	InsertList(head2,6);
	InsertList(head2,8);
	ShowList(mergeTwoLists(head1,head2));
	return 0;
}
