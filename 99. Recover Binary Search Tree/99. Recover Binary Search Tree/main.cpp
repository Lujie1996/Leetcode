//
//  main.cpp
//  99. Recover Binary Search Tree
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        // in-order traverse the BST, the correct sequence should be increasing
        // find the first and second elements that breaks the increasing, and swap those two elements
        
        if (root == NULL)
            return;
    
        traverse(root->left);
        
        if (firstElement == NULL && prevElement->val >= root->val) {
            firstElement = prevElement; // prev is picked as first
        }
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root; // root is picked as second
        }
        // it's very magical to solve this as a general problem: to find the pairs of numbers which have been swapped in a sorted list,
        // e.g. 6 3 4 5 2, there is one pair of numbers that are swapped
        // use the method above, when i points to 3, firstElement = 6, secondElement  = 3; ...; when i points to 2, secondElement = 2
        // that is the result is 6 and 2
        prevElement = root;
        
        traverse(root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
