//
//  main.cpp
//  230. Kth Smallest Element in a BST
//
//  Created by Jie Lu on 2018/4/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void createTree(TreeNode*& t){//preorder create node
    char ch;
    cin>>ch;
    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=(TreeNode*)malloc(sizeof(TreeNode));
        t->val=ch;
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
// iteratively version 1 2018/4/17
//void inOrderTraverse(TreeNode* root, vector<int>& nums, int k){
//    if(root!=NULL&&nums.size()!=k){
//        inOrderTraverse(root->left,nums,k);
//        nums.push_back(root->val);
//        if(nums.size()==k)
//            return;
//        inOrderTraverse(root->right,nums,k);
//    }
//}
//int kthSmallest(TreeNode* root, int k){
//    vector<int> nums;
//    inOrderTraverse(root,nums,k);
//    return nums[k-1];
//}

// recursively 2018/4/17
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (--k == 0) {
            break;
        }
        root = root->right;
    }
    return root->val;
}

// iteratively version 2 2018/9/4
// int inOrder(TreeNode* root, int k, int& res) {
//     if (root == NULL) {
//         return 0;
//     }
//     int left = inOrder(root->left, k, res);
//     if (left == -1) {
//         return -1;
//     }
//     if (left + 1 == k) {
//         res = root->val;
//         return -1;
//     }
//     int right = inOrder(root->right, k - left - 1, res);
//     if (right == -1) {
//         return -1;
//     }
//     return left + right + 1;
// }
// int kthSmallest(TreeNode * root, int k) {
//     // write your code here
//     int res = 0;
//     inOrder(root, k, res);
//     return res;
// }

int main(){
    TreeNode* root;
    createTree(root);
    showTree(root);
    int k;
    cout<<"kthSmallest"<<endl;
    while(cin>>k)
        cout<<kthSmallest(root,k)-('0'-0)<<endl;
    return 0;
}

