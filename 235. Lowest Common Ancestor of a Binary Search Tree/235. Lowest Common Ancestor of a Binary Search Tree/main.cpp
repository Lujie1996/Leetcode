//
//  main.cpp
//  235. Lowest Common Ancestor of a Binary Search Tree
//
//  Created by Jie Lu on 2018/5/4.
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
int countSubTree(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
    int count = 0;
    if (root == NULL) {
        return 0;
    }
    int countLeft = countSubTree(root->left, p, q, res);
    if (countLeft == -1) {
        return -1;
    }
    int countRight = countSubTree(root->right, p, q, res);
    if (countRight == -1) {
        return -1;
    }
    count += countLeft;
    count += countRight;
    if (root == p || root == q) {
        count++;
    }
    if (count == 2) {
        res = root;
        return -1;
    }
    return count;
}
/*
 Actually this solution works fine for both
 235. Lowest Common Ancestor of a Binary Search Tree & 236. Lowest Common Ancestor of a Binary Tree.
 The time cost is pretty good, beats over 90%.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* res;
    res = countSubTree(root, p, q, res) ? res : NULL;
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    TreeNode *p = root, *q = root->right;
    cout<<lowestCommonAncestor(root, p, q)->val<<endl;
    return 0;
}
