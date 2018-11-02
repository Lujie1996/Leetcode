//
//  main.cpp
//  124. Binary Tree Maximum Path Sum
//
//  Created by Jie Lu on 2018/8/9.
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
void createTree(TreeNode*& t){
    //preorder create node
    int ch;
    cin>>ch;
    if(ch == 0)
    {
        t = NULL;
    }
    else
    {
        t = (TreeNode*)malloc(sizeof(TreeNode));
        t->val = ch;
        createTree(t->left);
        createTree(t->right);
    }
}

struct MaxSum {
    int maxOneSide, maxAll;
    MaxSum(int a, int b): maxOneSide(a), maxAll(b) {}
};

MaxSum dfs(TreeNode* root) {
    if (root == NULL) {
        return MaxSum(INT_MIN, INT_MIN);
    }
    
    MaxSum left = dfs(root->left), right = dfs(root->right);
    
    int maxOneSide = INT_MIN, maxAll = INT_MIN;
    
    maxOneSide = root->val + max(0, max(left.maxOneSide, right.maxOneSide));
    
    // for maxAll, it consider three conditions
    // 1. consider maxOneSide (including only current node)
    maxAll = maxOneSide;
    
    // 2. consider starting from maxOneSide(left) to current node to maxOneSide(right)
    if (root->left && root->right) {
        maxAll = max(maxAll, root->val + left.maxOneSide + right.maxOneSide);
    }
    
    // 3, consider maxAll of children nodes
    maxAll = max(maxAll, max(left.maxAll, right.maxAll));
    
    return MaxSum(maxOneSide, maxAll);
}
int maxPathSum(TreeNode* root) {
    return dfs(root).maxAll;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<maxPathSum(root)<<endl;
    return 0;
}
