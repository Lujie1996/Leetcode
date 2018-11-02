//
//  main.cpp
//  83. Remove Duplicates from Sorted List
//
//  Created by Jie Lu on 2018/4/9.
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
}
//This solution follows the idea of Remove Duplicates fron Sorted Array
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *p = head, *q = head; // q goes faster
    while (q->next) {
        while (q->next && q->val != q->next->val) {
            p->val = q->val;
            q = q->next;
            p = p->next;
        }
        while (q->next && q->val == q->next->val) {
            q = q->next;
        }
    }
    p->val = q->val;
    p->next = NULL;
    return head;
}
//Another idea, just use cur->next = cur->next->next to jump over the duplicates.
//ListNode *deleteDuplicates(ListNode *head) {
//    ListNode* cur = head;
//    while (cur) {
//        while (cur->next && cur->val == cur->next->val)
//            cur->next = cur->next->next;
//        cur = cur->next;
//    }
//    return head;
//}

int main(int argc, const char * argv[]) {
    ListNode *root = new ListNode(1);
    insertListNode(root);
    root = deleteDuplicates(root);
    printList(root);
    return 0;
}
