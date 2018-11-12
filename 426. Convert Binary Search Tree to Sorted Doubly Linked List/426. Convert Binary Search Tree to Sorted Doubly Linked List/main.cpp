//
//  main.cpp
//  426. Convert Binary Search Tree to Sorted Doubly Linked List
//
//  Created by Jie Lu on 2018/11/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

// Use stack to implement in-order traverse
Node* treeToDoublyList(Node* root) {
    if (root == NULL) {
        return root;
    }
    
    stack<Node*> st;
    Node *node = root, *pre = NULL, *newRoot = NULL;
    while (node || !st.empty()) {
        while (node) {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        if (pre == NULL) {
            newRoot = node;
        }
        else {
            node->left = pre;
            pre->right = node;
        }
        pre = node;
        node = node->right;
    }
    newRoot->left = pre;
    pre->right = newRoot;
    
    return newRoot;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
