//
//  main.cpp
//  117. Populating Next Right Pointers in Each Node II
//
//  Created by Jie Lu on 2018/10/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    TreeLinkNode *head = NULL, *cur = root, *pre = NULL;
    while (cur) {
        while (cur) {
            // push left
            if (cur->left) {
                if (pre != NULL) {
                    pre->next = cur->left;
                }
                else {
                    head = cur->left;
                }
                pre = cur->left;
            }
            
            // push right
            if (cur->right) {
                if (pre != NULL) {
                    pre->next = cur->right;
                }
                else {
                    head = cur->right;
                }
                pre = cur->right;
            }
            
            cur = cur->next;
        }
        cur = head;
        pre = NULL;
        head = NULL;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
