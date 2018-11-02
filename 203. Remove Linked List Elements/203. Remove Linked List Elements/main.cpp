//
//  main.cpp
//  203. Remove Linked List Elements
//
//  Created by Jie Lu on 2018/4/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void insertListNode(ListNode* head) {
    int x;
    cin >> x;
    if (x == 0) {
        head = NULL;
        return;
    }
    head->next = new ListNode(x);
    insertListNode(head->next);
}
void printList(ListNode* head) {
    ListNode* p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout<<endl;
}
ListNode* removeElements(ListNode* head, int val) {
    ListNode* tmpHead = new ListNode(0);
    tmpHead->next = head;
    ListNode* p = tmpHead;
    while (p) {
        if (p->next && p->next->val == val) {
            ListNode* newNext = p->next->next ? p->next->next : NULL;
            p->next = newNext;
        }
        else
            p = p->next;
    }
    return tmpHead->next;
}
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    insertListNode(head);
    head = removeElements(head, 1);
    printList(head);
    return 0;
}
