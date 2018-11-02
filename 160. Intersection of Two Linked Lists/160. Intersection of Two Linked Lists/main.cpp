//
//  main.cpp
//  160. Intersection of Two Linked Lists
//
//  Created by Jie Lu on 2018/4/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB, *big, *small;
    int len1 = 0, len2 = 0, diff = 0;
    while (p) {
        p = p->next;
        len1++;
    }
    while (q) {
        q = q->next;
        len2++;
    }
    if (p != q) {
        return NULL;
    }
    if (len1 > len2) {
        big = headA;
        small = headB;
        diff = len1 - len2;
    }
    else {
        big = headB;
        small = headA;
        diff = len2 - len1;
    }
    for (int i = 0; i < diff; i++) {
        big = big->next;
    }
    while (big != small) {
        big = big->next;
        small = small->next;
    }
    return big;
}
int main(int argc, const char * argv[]) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node5;
    node4->next = node5;
    node5->next = node6;
    cout<<getIntersectionNode(node1, node4)->val<<endl;
    return 0;
}
