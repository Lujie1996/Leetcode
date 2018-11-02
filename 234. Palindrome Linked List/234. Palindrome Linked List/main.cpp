//
//  main.cpp
//  234. Palindrome Linked List
//
//  Created by Jie Lu on 2018/5/2.
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
bool isPalindrome(ListNode* head) {
    ListNode *rev, *slow, *fast;
    rev = NULL;
    slow = fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        ListNode* temprev = rev;
        rev = slow;
        slow = slow->next;
        rev->next = temprev;
    }
    if (fast)
        slow = slow->next;
    while (rev && rev->val == slow->val) {
        slow = slow->next;
        rev = rev->next;
    }
    return !rev;
}
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    insertListNode(head);
    if (isPalindrome(head)) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
