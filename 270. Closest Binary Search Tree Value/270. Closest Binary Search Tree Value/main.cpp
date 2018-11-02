//
//  main.cpp
//  270. Closest Binary Search Tree Value
//
//  Created by Jie Lu on 2018/6/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <cmath>
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

int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    while (root) {
        if (abs(closest - target) >= abs(root->val - target))
            closest = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return closest;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<closestValue(root, 3.6)<<endl;
    return 0;
}
