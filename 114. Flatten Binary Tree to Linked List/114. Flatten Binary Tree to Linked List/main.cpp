//
//  main.cpp
//  114. Flatten Binary Tree to Linked List
//
//  Created by Jie Lu on 2018/4/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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

// Solution fron discuss 2018/4/20
//TreeNode* prevNode = NULL;
//void flatten(TreeNode* root) {
//    // right_to_left_direction postorder traverse
//    if (root == NULL) {
//        return;
//    }
//    flatten(root->right);
//    flatten(root->left);
//    root->right = prevNode;
//    root->left = NULL;
//    prevNode = root;
//}

// My original code 2018/9/3
void flatten(TreeNode * root) {
    // write your code here
    if (root == NULL) {
        return;
    }
    flatten(root->left);
    flatten(root->right);
    if (root->left == NULL) {
        return;
    }
    TreeNode *preRight = root->right, *p = root->left;
    while (p->right) {
        p = p->right;
    }
    p->right = preRight;
    root->right = root->left;
    root->left = NULL;
}

int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    flatten(root);
    showTree(root);
    return 0;
}
