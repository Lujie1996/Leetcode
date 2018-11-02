//
//  main.cpp
//  105. Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by Jie Lu on 2018/4/19.
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
TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
//    int len = preR - preL;
//    cout<<"preOrder: ";
//    for (int i = 0; i <= len; i++) {
//        cout<<preorder[preL + i]<<" ";
//    }
//    cout<<endl;
//    cout<<"inOrder : ";
//    for (int i = 0; i <= len; i++) {
//        cout<<inorder[inL + i]<<" ";
//    }
//    cout<<endl;
    if (preL > preR || inL > inR) {
        return NULL;
    }
    if (preL == preR) {
        return new TreeNode(preorder[preR]);
    }
    int rootVal = preorder[preL], lenOfLeftSub = 1;
    TreeNode* root = new TreeNode(rootVal);
    if (inorder[inL] == rootVal) {
        lenOfLeftSub = 0;
    }
    else {
        while (inorder[inL + lenOfLeftSub] != rootVal) {
            lenOfLeftSub++;
        }
    }
    root->left = buildSubTree(preorder, inorder, preL+1, preL+lenOfLeftSub, inL, inL+lenOfLeftSub-1);
    root->right = buildSubTree(preorder, inorder, preL+lenOfLeftSub+1, preR, inL+lenOfLeftSub+1, inR);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
        return NULL;
    }
    return buildSubTree(preorder, inorder, 0, (int)preorder.size()-1, 0, (int)inorder.size()-1);
}
int main(int argc, const char * argv[]) {
    int a[] = {1,2};
    int b[] = {1,2};
    vector<int> preorder(a,a+2);
    vector<int> inorder(b,b+2);
    TreeNode* root = buildTree(preorder, inorder);
    showTree(root);
    return 0;
}
