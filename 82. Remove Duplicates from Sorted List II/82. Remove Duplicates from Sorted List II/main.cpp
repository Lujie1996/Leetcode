//
//  main.cpp
//  82. Remove Duplicates from Sorted List II
//
//  Created by Jie Lu on 2018/4/12.
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
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
        return head;
    }
    ListNode *p, *q, *newHead;
    bool startFlag = true;
    p = q = newHead = head;
    while (q && q->next) {
        while (q->next) {
            if (q->val != q->next->val) {
                if (startFlag)
                {
                    newHead = p;
                    startFlag = false;
                }
                else
                    p = p->next;
                q = q->next;
            }
            else
                break;
        }
        if (!q->next) {
            break;
        }
        // following codes are only applied when there are duplicates on q and q->next
        while (q->next) {
            if (q->next->val == q->val) {
                q = q->next;
            }
            else
                break;
        }
        if ((p == newHead) && (p->val == q->val)) {
            // p is list head and p, q have same value, the beginning nodes have duplicates, need a new head
            p = q->next;
            newHead = p;
        }
        else {
            // if p, q have different values, the previous while() loops on q->val, not p->val, keep present head
            p->next = q->next;
        }
        q = q->next;
    }
    return newHead;
}
int main(int argc, const char * argv[]) {
    ListNode* root = new ListNode(1);
    insertListNode(root);
    root = deleteDuplicates(root);
    printList(root);
    return 0;
}
