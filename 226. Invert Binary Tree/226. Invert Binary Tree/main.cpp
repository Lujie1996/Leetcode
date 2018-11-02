//
//  main.cpp
//  226. Invert Binary Tree
//
//  Created by Jie Lu on 2018/5/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <queue>
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
    if(root != NULL){
        cout << root->val << endl;
        showTree(root->left);
        showTree(root->right);
    }
}
//TreeNode* invertTree(TreeNode* root) {
//    if (root == NULL) {
//        return NULL;
//    }
//    root->right = invertTree(root->right);
//    root->left = invertTree(root->left);
//    TreeNode* tmp = root->right;
//    root->right = root->left;
//    root->left = tmp;
//    return root;
//}
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode* thisNode = Q.front();
        Q.pop();
        TreeNode* tmp = thisNode->left;
        thisNode->left = thisNode->right;
        thisNode->right = tmp;
        if (thisNode->left) {
            Q.push(thisNode->left);
        }
        if (thisNode->right) {
            Q.push(thisNode->right);
        }
    }
    return root;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    root = invertTree(root);
    showTree(root);
    return 0;
}
