//
//  main.cpp
//  109. Convert Sorted List to Binary Search Tree
//
//  Created by Jie Lu on 2018/4/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
void createTree(TreeNode*& t){//preorder create node
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=(TreeNode*)malloc(sizeof(TreeNode));
        t->val=ch-'0';
        createTree(t->left);
        createTree(t->right);
    }
}
void showTree(TreeNode* root){//preorder
    if(root!=NULL){
        cout<<root->val<<endl;
        showTree(root->left);
        showTree(root->right);
    }
}
int listLen(ListNode* head) {
    ListNode* runner = head;
    int i = 0;
    while (runner) {
        runner = runner->next;
        i++;
    }
    return i;
}
TreeNode* getBST(ListNode*& list, int len) {
    if (len == 0) {
        return NULL;
    }
    TreeNode* root = new TreeNode(0);
    root->left = getBST(list, len / 2);
    root->val = list->val;
    list = list->next;
    root->right = getBST(list, len - len / 2 - 1);
    return root;
}
TreeNode* sortedListToBST(ListNode* head) {
    return getBST(head, listLen(head));
}
int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(-10);
    insertListNode(head);
    TreeNode* root = sortedListToBST(head);
    showTree(root);
    return 0;
}
