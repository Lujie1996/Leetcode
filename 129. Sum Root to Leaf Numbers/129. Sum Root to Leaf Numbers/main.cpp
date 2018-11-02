//
//  main.cpp
//  129. Sum Root to Leaf Numbers
//
//  Created by Jie Lu on 2018/4/22.
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
void getSum(TreeNode* root, int base, int& res) {
    base = base * 10 + root->val;
    if (!root->left && !root->right) {
        // leaf node! add the sum of this path to res
        res += base;
        return;
    }
    if (root->left) {
         getSum(root->left, base, res);
    }
    if (root->right) {
        getSum(root->right, base, res);
    }
}
int sumNumbers(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int res = 0;
    getSum(root, 0, res);
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<sumNumbers(root)<<endl;
    return 0;
}
