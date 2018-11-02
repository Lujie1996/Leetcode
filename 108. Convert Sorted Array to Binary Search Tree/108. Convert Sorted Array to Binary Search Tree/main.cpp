//
//  main.cpp
//  108. Convert Sorted Array to Binary Search Tree
//
//  Created by Jie Lu on 2018/4/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
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
    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=(TreeNode*)malloc(sizeof(TreeNode));
        t->val=ch-'0';
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
TreeNode* getBST(vector<int>& nums, int start, int end) {
//    cout<<start<<" "<<end<<endl;
    if (start > end) {
        return NULL;
    }
    if (start == end) {
        return new TreeNode(nums[start]);
    }
    int mid = start + (end - start + 1) / 2;
    int rootVal = nums[mid];
    TreeNode* root = new TreeNode(rootVal);
    root->left = getBST(nums, start, mid - 1);
    root->right = getBST(nums, mid + 1, end);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return getBST(nums, 0, (int)nums.size()-1);
}
int main(int argc, const char * argv[]) {
    int a[] = {-10,-3,0,5,9};
    vector<int> nums(a,a+5);
    TreeNode* root = sortedArrayToBST(nums);
    showTree(root);
    return 0;
}
