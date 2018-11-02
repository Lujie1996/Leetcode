//
//  main.cpp
//  107. Binary Tree Level Order Traversal II
//
//  Created by Jie Lu on 2018/4/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    if(root!=NULL){
        cout<<root->val<<endl;
        showTree(root->left);
        showTree(root->right);
    }
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> q;
    vector<int> layer;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* thisNode = q.front();
        q.pop();
        if (thisNode == NULL) {
            res.push_back(layer);
            layer.clear();
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else{
            layer.push_back(thisNode->val);
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
    }
    for (int i = 0; i < layer.size(); i++) {
        cout<<layer[i]<<" ";
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<vector<int>> res = levelOrderBottom(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
