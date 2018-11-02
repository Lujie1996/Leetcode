//
//  main.cpp
//  145. Binary Tree Postorder Traverse
//
//  Created by Jie Lu on 2018/4/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
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
//  Similar to the preorderTraverse above, push left child first and at last reverse the result.
//  This looks like use BFS to traverse the tree, scan it by layer
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL) {
        return res;
    }
    stack<TreeNode*> st;
    TreeNode* top;
    st.push(root);
    while(!st.empty()) {
        top = st.top();
        st.pop();
        res.push_back(top->val);
        if(top->left) {
            st.push(top->left);
        }
        if(top->right) {
            st.push(top->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
//Another implementation
//vector<int> postorderTraversal(TreeNode* root) {
//    vector<int> res;
//    stack<TreeNode*> st;
//    while (!st.empty() || root != NULL) {
//        if (root) {
//            st.push(root);
//            res.insert(res.begin(), root->val); // Reverse the push_back() in preorderTraverse, insert from begin
//            root = root->right; // Right child first
//        }
//        else {
//            TreeNode* t = st.top();
//            st.pop();
//            root = t->left;
//        }
//    }
//    return res;
//}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
