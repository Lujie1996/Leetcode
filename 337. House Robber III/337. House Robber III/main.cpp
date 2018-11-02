//
//  main.cpp
//  337. House Robber III
//
//  Created by Jie Lu on 2018/5/27.
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
// This is my original solution. Solve it for only 15min ：）
void getMaxProfit(TreeNode* root, int& profitIncludeRoot, int& profitExcludeRoot) {
    if (!root) {
        profitIncludeRoot = 0;
        profitExcludeRoot = 0;
        return;
    }
    int a, b, c, d;
    getMaxProfit(root->left, a, b);
    getMaxProfit(root->right, c, d);
    profitIncludeRoot = b + d + root->val;
    profitExcludeRoot = max(a, b) + max(c, d);
}
int rob(TreeNode* root) {
    int a, b;
    getMaxProfit(root, a, b);
    return max(a, b);
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<rob(root)<<endl;
    return 0;
}
