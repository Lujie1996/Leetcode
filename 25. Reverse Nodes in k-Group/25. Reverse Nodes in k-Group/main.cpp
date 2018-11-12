//
//  main.cpp
//  25. Reverse Nodes in k-Group
//
//  Created by Jie Lu on 2018/11/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    ListNode* p = head;
    while(p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout<<endl;
}

void reverse(ListNode* head) {
    if (!head) {
        return;
    }
    ListNode *pre = NULL, *p = head, *nextP = head->next;
    while (p) {
        nextP = p->next;
        p->next = pre;
        pre = p;
        p = nextP;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *p = head, *newHead = NULL, *pre = NULL, *start = head, *nextStart = NULL;
    while (p) {
        start = p;
        int count = 1;
        while (p->next && count < k) {
            p = p->next;
            count++;
        }
        if (count != k) {
            if (pre) {
                pre->next = nextStart;
            }
            else {
                newHead = head;
            }
            break;
        }
        if (pre == NULL) {
            newHead = p;
        }
        else {
            pre->next = p;
        }
        nextStart = p->next;
        p->next = NULL;
        reverse(start);
        pre = start;
        p = nextStart;
    }
    return newHead;
}

int main(int argc, const char * argv[]) {
    ListNode* h1 = new ListNode(1);
    ListNode* h2 = new ListNode(2);
    ListNode* h3 = new ListNode(3);
    ListNode* h4 = new ListNode(4);
    ListNode* h5 = new ListNode(5);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    
    printList(reverseKGroup(h1, 2));
    return 0;
}

