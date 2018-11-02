//
//  main.cpp
//  173. Binary Search Tree Iterator
//
//  Created by Jie Lu on 2018/5/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushAllLeftChildren(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    
    BSTIterator(TreeNode *root) {
        pushAllLeftChildren(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* res = st.top();
        st.pop();
        pushAllLeftChildren(res->right);
        return res->val;
    }
};
int main(int argc, const char * argv[]) {
    
    return 0;
}
