//
//  main.cpp
//  112. Path Sum
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
bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }
    sum -= root->val;
    if (sum == 0 && root->left == NULL && root->right == NULL) {
        return true;
    }
    return (root->left && hasPathSum(root->left, sum)) || (root->right && hasPathSum(root->right, sum));
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    if (hasPathSum(root, 1)) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
