//
//  main.cpp
//  450. Delete Node in a BST
//
//  Created by Jie Lu on 2018/8/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
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
    if(ch == '#')
    {
        t = NULL;
    }
    else
    {
        t = (TreeNode*)malloc(sizeof(TreeNode));
        t->val = ch-'0';
        createTree(t->left);
        createTree(t->right);
    }
}
void showTree(TreeNode* root){//preorder
    if(root != NULL){
        cout<<root->val<<endl;
        showTree(root->left);
        showTree(root->right);
    }
}

/*
 Steps:
 1. Recursively find the node that has the same value as the key, while setting the left/right nodes equal to the returned subtree
 2. Once the node is found, have to handle the below 4 cases
 node doesn't have left or right - return null
 node only has left subtree - return the left subtree
 node only has right subtree - return the right subtree
 node has both left and right - find the minimum value in the right subtree, set that value to the currently found node, then recursively delete the minimum value in the right subtree
 */
TreeNode* findMin(TreeNode* node){
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            return root->right;
        }
        else if (root->right == NULL) {
            return root->left;
        }
        // both left and rigth children are not NULL
        // very smart idea. Set a value of a node(X) in subtree to the current node, then recursively delete that node X in the subtree.
        TreeNode* minNode = findMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    TreeNode* res = deleteNode(root, 1);
    showTree(res);
    return 0;
}
