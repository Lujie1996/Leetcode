//
//  main.cpp
//  99. Recover Binary Search Tree
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    // The reason for this initialization is to avoid null pointer exception in the first comparison when prevElement has not been initialized
    TreeNode* prevElement = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        // In order traversal to find the two elements
        traverse(root);
        
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    
    void traverse(TreeNode* root) {
        if (root == NULL)
            return;
        
        traverse(root->left);
        
        if (firstElement == NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }
        prevElement = root;
        
        traverse(root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
