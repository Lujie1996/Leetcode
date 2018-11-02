//
//  main.cpp
//  113. Path Sum II
//
//  Created by Jie Lu on 2018/4/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
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
void tryPath(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& cur) {
    sum -= root->val;
    cur.push_back(root->val);
    if (sum == 0 && !root->left && !root->right) {
        res.push_back(cur);
        return;
    }
    if (root->left) {
        tryPath(root->left, sum, res, cur);
        cur.pop_back();
    }
    if (root->right) {
        tryPath(root->right, sum, res, cur);
        cur.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }
    vector<int> cur;
    tryPath(root, sum, res, cur);
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<vector<int>> res = pathSum(root, 6);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
