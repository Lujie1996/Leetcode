//
//  main.cpp
//  98. Validate Binary Search Tree
//
//  Created by Jie Lu on 2018/4/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Data{
    int lmax;
    int rmin;
    Data(int a, int b) : lmax(a), rmin(b) {}
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
        t = new TreeNode(ch-'0');
        createTree(t->left);
        createTree(t->right);
    }
}
void showTree(TreeNode* root){//preorder
    if(root!=NULL){
        cout<<root->val<<endl;
        showTree(root->left);
        showTree(root->right);
    }
}
//从上往下的判断；向左孩子看，root影响最大值；向右孩子看，root影响最小值。可以写一个BST然后把每个节点的取值范围写出来，观察出规律
//bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
//    if(!root)
//        return true;
//    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
//        return false;
//    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
//}
//bool isValidBST(TreeNode* root) {
//    return isValidBST(root, NULL, NULL);
//}

//中序遍历，根据性质：BST的中序遍历结果为递增数列
bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    stack<TreeNode*> st;
    TreeNode* pre = NULL;
    while (root != NULL || !st.empty()) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if(pre != NULL && root->val <= pre->val)
            return false;
        pre = root;
        root = root->right;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    if (isValidBST(root)) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
