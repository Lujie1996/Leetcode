//
//  main.cpp
//  144. Binary Tree Preorder Traversal
//
//  Created by Jie Lu on 2018/4/23.
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
//vector<int> preorderTraversal(TreeNode* root) {
//    vector<int> res;
//    if (root == NULL) {
//        return res;
//    }
//    stack<TreeNode*> st;
//    st.push(root);
//    TreeNode* top;
//    while (!st.empty()) {
//        top = st.top();
//        st.pop();
//        res.push_back(top->val);
//        // IMPORTANT: push right child first!!! if pushing left child first, then it's right-to-left preorder traverse
//        if (top->right) {
//            st.push(top->right);
//        }
//        if (top->left) {
//            st.push(top->left);
//        }
//    }
//    return res;
//}

//My original implementation
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    while (!st.empty() || root != NULL) {
        if (root) {
            st.push(root);
            res.push_back(root->val);
            root = root->left;
        }
        else {
            TreeNode* t = st.top();
            st.pop();
            root = t->right;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<int> res = preorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
