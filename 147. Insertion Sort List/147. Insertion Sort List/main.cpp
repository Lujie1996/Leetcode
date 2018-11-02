//
//  main.cpp
//  147. Insertion Sort List
//
//  Created by Jie Lu on 2018/4/24.
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
// The left part of list is ordered, the remaining right part is not ordered.
// Traverse through the unordered part by pointer preCur.
// Find a place in the ordered part which preCur->next could insert into.
ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* tmpHead = new ListNode(0);
    tmpHead->next = head;
    ListNode *preCur, *cur, *p;
    preCur = cur = p = tmpHead;
    while (preCur->next) {
        cur = preCur->next;
        p = tmpHead;
        while (p != cur && p->next->val <= cur->val) {
            p = p->next;
        }
        if (p == cur) {
            preCur = preCur->next;
            continue;
        }
        ListNode* pNext = p->next;
        ListNode* curNext = cur->next;
        p->next = cur;
        cur->next = pNext;
        preCur->next = curNext;
    }
    return tmpHead->next;
}
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(4);
    insertListNode(head);
    head = insertionSortList(head);
    printList(head);
    return 0;
}
