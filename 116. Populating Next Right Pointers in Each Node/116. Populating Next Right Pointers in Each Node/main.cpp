//
//  main.cpp
//  116. Populating Next Right Pointers in Each Node
//
//  Created by Jie Lu on 2018/10/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

void connect(TreeLinkNode *root) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        return;
    }
    
    root->left->next = root->right;
    if (root->next) {
        root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
