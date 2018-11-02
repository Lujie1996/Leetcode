//
//  main.cpp
//  101. Symmetric Tree
//
//  Created by Jie Lu on 2018/3/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void createTree(TreeNode*& t){//preorder create node
    char ch;
    cin >> ch;
    if(ch=='#')
    {
        t = NULL;
    }
    else
    {
        t = new TreeNode(ch);
        createTree(t->left);
        createTree(t->right);
    }
}
void showTree(TreeNode* root){//preorder
    if(root != NULL){
        cout << root->val << endl;
        showTree(root->left);
        showTree(root->right);
    }
}
bool isPairSym(TreeNode* a, TreeNode* b) {
    if(a==NULL&&b==NULL)
       return true;
    if(!a||!b)
        return false;
    if(a->val!=b->val)
        return false;
    if(isPairSym(a->left, b->right)&&isPairSym(a->right, b->left))
        return true;
    else
        return false;
}
bool isSymmetric(TreeNode* root) {
    if(root==NULL)
        return true;
    return isPairSym(root->left, root->right);
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    if(isSymmetric(root))
        cout << "yes" << endl;
    else
        cout<< "no" <<endl;
    return 0;
}
