//
//  main.cpp
//  86. Partition List
//
//  Created by Jie Lu on 2018/4/13.
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
// From other person on LC, very smart solution, the fundamental principles are to separate the list into 2 distinct lists and link them afterwards.
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}
// Below is my original solution, which is rather complex :(
//ListNode* partition(ListNode* head, int x) {
//    if (!head) {
//        return head;
//    }
//    ListNode *p, *q, *newHead;
//    p = q = newHead = head;
//    if (p->val < x) {
//        while (p->next && p->next->val < x) {
//            p = p->next;
//        }
//    }
//    q = p;
//    while (q->next) {
//        while (q->next && q->next->val >= x) {
//            q = q->next;
//        }
//        if (q->next) {
//            ListNode *small = q->next;
//            // small -> node whose value is less than x, it will be moved to the front of list
//            if (p == newHead && p->val >= x) {
//                q->next = q->next->next;
//                small->next = p;
//                newHead = small;
//                p = newHead;
//            }
//            else {
//                ListNode *tmp; // tmp -> the node rightside of where the small node will insert
//                tmp = p->next;
//                q->next = q->next->next;
//                p->next = small;
//                small->next = tmp;
//                p = p->next;
//            }
//        }
//        else
//            break;
//    }
//    return newHead;
//}
int main(int argc, const char * argv[]) {
    ListNode *root = new ListNode(1);
    insertListNode(root);
    root = partition(root, 3);
    printList(root);
    return 0;
}
