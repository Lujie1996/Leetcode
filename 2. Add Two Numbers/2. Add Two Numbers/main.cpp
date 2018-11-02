//
//  main.cpp
//  2. Add Two Numbers
//
//  Created by Jie Lu on 14/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* insertNode(){
    char data;
    cout<<"insert val ('#' to end): ";
    cin>>data;
    if(data=='#')
        return NULL;
    data-=('0'-0);
    ListNode* node=new ListNode(data);
    node->next=insertNode();
    return node;
}
void displayList(ListNode* head){
    ListNode* t=head;
    while(t!=NULL){
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode head(0);
    ListNode* p=&head;
    int extra=0;
    while(l1||l2||extra){
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+extra;
        extra=sum/10;
        p->next=new ListNode(sum%10);
        p=p->next;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }
    return head.next;
}
int main(int argc, const char * argv[]) {
    ListNode* l1=insertNode();
    ListNode* l2=insertNode();
    displayList(addTwoNumbers(l1, l2));
    return 0;
}
