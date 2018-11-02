//
//  main.cpp
//  701. Insert into a Binary Search Tree
//
//  Created by Jie Lu on 2018/10/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* r = root;
    while (root) {
        if (val > root->val) {
            if (root->right) {
                root = root->right;
            }
            else {
                root->right = new TreeNode(val);
                return r;
            }
        }
        else {
            if (root->left) {
                root = root->left;
            }
            else {
                root->left = new TreeNode(val);
                return r;
            }
        }
    }
    root->val = val;
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
