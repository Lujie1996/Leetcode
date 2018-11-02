//
//  main.cpp
//  110. Balanced Binary Tree
//
//  Created by Jie Lu on 2018/4/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <algorithm>
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
int depth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
        return -1;
    }
    return max(leftDepth,rightDepth) + 1;
}
bool isBalanced(TreeNode* root) {
    if (depth(root) == -1) {
        return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    if (isBalanced(root)) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
