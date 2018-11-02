//
//  main.cpp
//  111. Minimum Depth of Binary Tree
//
//  Created by Jie Lu on 2018/4/20.
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
    if(root!=NULL){
        cout<<root->val<<endl;
        showTree(root->left);
        showTree(root->right);
    }
}
int minDepth(TreeNode* root) {
    // BFS solves this problem very fast
    if (root == NULL) {
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int depth = 0;
    while (!q.empty()) {
        TreeNode* thisNode = q.front();
        q.pop();
        if (thisNode == NULL) {
            if (!q.empty()) {
                q.push(NULL);
            }
            depth++;
        }
        else{
            if (thisNode->left == NULL && thisNode->right == NULL) {
                break;
            }
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
    }
    return depth + 1;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    cout<<minDepth(root)<<endl;
    return 0;
}
