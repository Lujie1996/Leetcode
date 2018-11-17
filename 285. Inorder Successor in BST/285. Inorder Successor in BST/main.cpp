//
//  main.cpp
//  285. Inorder Successor in BST
//
//  Created by Jie Lu on 2018/11/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> st;
    bool found = false;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (found) {
            return root;
        }
        if (root == p) {
            found = true;
        }
        root = root->right;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
