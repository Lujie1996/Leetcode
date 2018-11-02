//
//  main.cpp
//  237. Delete Node in a Linked List
//
//  Created by Jie Lu on 2018/5/4.
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
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    insertListNode(head);
    ListNode* todelete = head->next->next;
    deleteNode(todelete);
    printList(head);
    return 0;
}
