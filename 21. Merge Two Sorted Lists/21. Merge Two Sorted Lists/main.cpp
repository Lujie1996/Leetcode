//
//  main.cpp
//  21. Merge Two Sorted Lists
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* tmpHead = new ListNode(0);
    ListNode* p = tmpHead;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1) {
        p->next = l1;
    }
    else if (l2) {
        p->next = l2;
    }
    return tmpHead->next;
}
int main(int argc, const char * argv[]) {
    ListNode* head1 = new ListNode(2);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(6);
    ListNode* head2 = new ListNode(1);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(7);
    head1->next = node1;
    node1->next = node2;
    head2->next = node3;
    node3->next = node4;
    head1 = mergeTwoLists(head1, head2);
    printList(head1);
    return 0;
}
