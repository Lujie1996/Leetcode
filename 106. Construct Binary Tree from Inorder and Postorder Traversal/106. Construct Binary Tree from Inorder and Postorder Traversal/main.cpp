//
//  main.cpp
//  106. Construct Binary Tree from Inorder and Postorder Traversal
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
TreeNode* buildSubTree(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR) {
    if (inL > inR || postL > postR) {
        return NULL;
    }
    if (inL == inR) {
        return new TreeNode(inorder[inL]);
    }
    
//    int len = inR - inL;
//    cout<<"inOrder  : ";
//    for (int i = 0; i <= len; i++) {
//        cout<<inorder[inL + i]<<" ";
//    }
//    cout<<endl;
//    cout<<"postOrder: ";
//    for (int i = 0; i <= len; i++) {
//        cout<<postorder[postL + i]<<" ";
//    }
//    cout<<endl;
    
    int rootVal = postorder[postR], lenOfLeftSub = 1;
    TreeNode* root = new TreeNode(rootVal);
    if (inorder[inL] == rootVal) {
        lenOfLeftSub = 0;
    }
    else {
        while (inorder[inL + lenOfLeftSub] != rootVal) {
            lenOfLeftSub++;
        }
    }
    root->left = buildSubTree(inorder, postorder, inL, inL+lenOfLeftSub-1, postL, postL+lenOfLeftSub-1);
    root->right = buildSubTree(inorder, postorder, inL+lenOfLeftSub+1, inR, postL+lenOfLeftSub, postR-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) {
        return NULL;
    }
    return buildSubTree(inorder, postorder, 0, (int)inorder.size()-1, 0, (int)postorder.size()-1);
}
int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4};
    int b[] = {3,2,4,1};
    vector<int> inorder(a,a+4);
    vector<int> postorder(b,b+4);
    TreeNode* root = buildTree(inorder, postorder);
    showTree(root);
    return 0;
}
