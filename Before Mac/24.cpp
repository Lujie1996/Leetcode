#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void Show(ListNode* head){
	ListNode* p=head;
	while(p->next!=NULL)
	{
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<p->val<<endl;
}
ListNode* swapPairs(ListNode* head) {
	if(head==NULL||head->next==NULL)
		return head;
	ListNode *p,*q,*t,*x,*result;
	p=head;
	q=p->next;
	x=q->next;
	t=NULL;
	result=q;
	while(p!=NULL&&q!=NULL)
	{
		q->next=p;
		p->next=NULL;
		if(t!=NULL)
			t->next=q;
		t=p;
		p=x;
		if(x!=NULL)
			q=p->next;	
		if(q!=NULL)
			x=q->next;
	}
	if(p!=NULL)
		t->next=p;
	return result;
}
ListNode* InsertNode(ListNode* head,int v){
	ListNode* t,*p;
	p=head;
	t=(ListNode*)malloc(sizeof(ListNode));
	t->val=v;
	t->next=NULL;
	while(p->next!=NULL)
		p=p->next;
	p->next=t;
	return head;
}
int main(){
	ListNode* head;
	head=(ListNode*)malloc(sizeof(ListNode));
	head->val=1;
	head->next=NULL;
	InsertNode(head,2);
	InsertNode(head,3);
	InsertNode(head,4);
	Show(swapPairs(head));
	return 0;
}
