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
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    insertListNode(head);
    reorderList(head);
    printList(head);
    return 0;
}
