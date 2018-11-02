//
//  main.cpp
//  250. Count Univalue Subtrees
//
//  Created by Jie Lu on 2018/6/8.
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
int helper(TreeNode* root, bool& ifValid) {
    if (root == NULL) {
        ifValid = true;
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        ifValid = true;
        return 1;
    }
    int thisTree = 0, leftCount, rightCount;
    bool leftValid, rightValid;
    leftCount = helper(root->left, leftValid);
    rightCount = helper(root->right, rightValid);
    if ((root->left && root->right && leftValid && rightValid && root->left->val == root->right->val && root->left->val == root->val) ||
       (root->left && root->right == NULL && leftValid && root->val == root->left->val) ||
       (root->left == NULL && root->right && rightValid && root->val == root->right->val)) {
        thisTree = 1;
        ifValid = true;
    }
    else {
        ifValid = false;
    }
    return leftCount + rightCount + thisTree;
}
int countUnivalSubtrees(TreeNode* root) {
    bool dummy;
    return helper(root, dummy);
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<countUnivalSubtrees(root)<<endl;
    return 0;
}
