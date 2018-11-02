//
//  main.cpp
//  156. Binary Tree Upside Down
//
//  Created by Jie Lu on 2018/6/6.
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

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || !root->left)
        return root;
    TreeNode* cur_left = root->left;
    TreeNode* cur_right = root->right;
    TreeNode* new_root = upsideDownBinaryTree(root->left);
    cur_left->right = root;
    cur_left->left = cur_right;
    root->left = nullptr;
    root->right = nullptr;
    return new_root;
}

/*
       1                1
     /  \             /
    2    3  ->      2 -- 3(left)
  / \             /
 4   5           4 -- 5(left)
 
 In the right side tree: 5,3 are the left children and 2,1 are the right children.
 4 is the root and the new tree is the one when you look it in this way. That is:
        4
       / \
      5   2
         /  \
        3    1
 */
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    TreeNode* newRoot = upsideDownBinaryTree(root);
    showTree(newRoot);
    return 0;
}
