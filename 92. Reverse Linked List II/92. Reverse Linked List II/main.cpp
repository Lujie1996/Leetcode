//
//  main.cpp
//  92. Reverse Linked List II
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
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) {
        return head;
    }
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    ListNode *preCur = newHead, *cur = head, *curNext, *begin, *end, *entry;
    int i = 1;
    while (i < m) {
        // let cur point to the mth node.
        preCur = preCur->next;
        cur = cur->next;
        i++;
    }
    /*
           m           n
     1 --> 2 --> 3 --> 4 --> 5
   begin entry
   preCur cur
     */
    begin = preCur;
    entry = cur;
    preCur = preCur->next;
    cur = cur->next;
    /*
     When reversing nodes, the arrow between preCur and cur needs to be reversed.
           m           n
     1 --> 2 --> 3 --> 4 --> 5
         preCur cur
     */
    while (i < n) {
        curNext = cur->next;
        cur->next = preCur;
        preCur = cur;
        cur = curNext;
        i++;
    }
    /*
           -----------------|
           |                \/
     1 --> 2 --> 3 --> 4 --> 5
     |                 /\
     |-----------------|
     
     */
    end = cur;
    begin->next = preCur;
    entry->next = end;
    return newHead->next;
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
    printList(reverseBetween(node1, 4, 5));
    return 0;
}
