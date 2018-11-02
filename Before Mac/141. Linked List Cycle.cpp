#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 
bool hasCycle(ListNode *head) {
	if(head==NULL||head->next==NULL)
		return false;
    ListNode *f=head,*s=head;
    while(f->next&&f->next->next){
    	f=f->next->next;
    	s=s->next;
		if(f==s)
			return true;
	}
	return false;
}
int main(){
	ListNode* head=(ListNode *)malloc(sizeof(ListNode));
	head->val=0;
	head->next=NULL;
	ListNode* pre=head;
	ListNode* fifth;
	for(int i=1;i<=5;i++){
		ListNode* tmp=(ListNode *)malloc(sizeof(ListNode));  
		tmp->val=i;
		tmp->next=NULL;
		pre->next=tmp;
		pre=tmp;
		if(i==5)
			fifth=tmp;
	}
	pre=fifth;
	for(int i=6;i<=7;i++){
		ListNode* tmp=(ListNode *)malloc(sizeof(ListNode));  
		tmp->val=i;
		tmp->next=NULL;
		pre->next=tmp;
		pre=tmp;
		if(i==7)
			tmp->next=fifth;
	}
	if(hasCycle(head))
		cout<<"has cycle"<<endl;
	else
		cout<<"no cycle"<<endl;
//	ListNode* tmp=head->next;
//	while(tmp!=NULL){
//		cout<<tmp->val<<" ";
//		tmp=tmp->next;
//	}
	return 0;
}
