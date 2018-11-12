//
//  main.cpp
//  143. Reorder List
//
//  Created by Jie Lu on 2018/4/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
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
void reorderList(ListNode* head) {
    if (head == NULL) {
        return;
    }
    vector<ListNode*> list;
    ListNode* p = head;
    while (p) {
        list.push_back(p);
        p = p->next;
    }
    p = head;
    ListNode *tail, *tmp;
    int n = (int)list.size();
    for (int i = n - 1; i >= (n+1) / 2; i--) {
        tail = list[i];
        tmp = p->next;
        p->next = tail;
        tail->next = tmp;
        p = tail->next;
    }
    p->next = NULL;
}
/*
 What if not use vector?
 use slow and fast pointers to split the list to two parts.
 Reverse the second half in place, and then insert the inversed second half into the first half.
 [1,2,3,4,5,6] -> [1,2,3],[4,5,6] -> [1,2,3],[6,5,4] -> [1,6,2,5,3,4]
 */

void reorderList(ListNode *head) {
    if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    p2 = head2->next;
    head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }
    
    // merge two lists: O(n)
    for (p1 = head, p2 = head2; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
    
    //for (p1 = head, p2 = head2; p2; ) {
    //    auto t = p1->next;
    //    p1->next = p2;
    //    p2 = p2->next;
    //    p1 = p1->next->next = t;
    //}
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    insertListNode(head);
    reorderList(head);
    printList(head);
    return 0;
}
