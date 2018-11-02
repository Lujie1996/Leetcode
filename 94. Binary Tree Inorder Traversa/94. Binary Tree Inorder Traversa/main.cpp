//
//  main.cpp
//  94. Binary Tree Inorder Traversa
//
//  Created by Jie Lu on 07/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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
//Recursive Solution:
//void inorder(vector<int>& res, TreeNode* root) {
//    if(root==NULL)
//        return;
//    inorder(res, root->left);
//    res.push_back(root->val);
//    inorder(res,root->right);
//}
//vector<int> inorderTraversal(TreeNode* root) {
//    vector<int> res;
//    inorder(res, root);
//    return res;
//}
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while (curr||!st.empty()) {
        //当左孩子不空就一直把左孩子压栈。当左孩子为空就弹栈记录其值，再将右孩子压栈。
        while (curr) {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        res.push_back(curr->val);
        st.pop();
        curr=curr->right;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<int> res = inorderTraversal(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
