//
//  main.cpp
//  206. Reverse Linked List
//
//  Created by Jie Lu on 2018/5/22.
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
ListNode* reverseList(ListNode* head) {
    if (head == NULL) {
        return head;
    }
    ListNode *cur, *preCur;
    cur = head->next;
    preCur = head;
    preCur->next = NULL;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = preCur;
        preCur = cur;
        cur = next;
    }
    return preCur;
}
int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    printList(reverseList(node1));
    return 0;
}
