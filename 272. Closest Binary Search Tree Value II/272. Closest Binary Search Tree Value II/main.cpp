//
//  main.cpp
//  272. Closest Binary Search Tree Value II
//
//  Created by Jie Lu on 2018/9/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
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

// Very intuitive solution. In-order traverse to get the whole sorted array of all values in BST, then get the k closest values.
// O(n) time and O(n) space
// Use queue to shrink the space to O(k)
vector<int> closestKValues(TreeNode * root, double target, int k) {
    // write your code here
    vector<int> nums;
    stack<TreeNode*> st;
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root  = root->left;
        }
        root = st.top();
        st.pop();
        nums.push_back(root->val);
        root = root->right;
    }
    int closeIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (fabs(nums[i] - target) < fabs((double)nums[closeIndex] - target)) {
            closeIndex = i;
        }
    }
    int i, j;
    vector<int> res;
    i = closeIndex;
    j = i + 1;
    while (j - i - 1 < k) {
        if (i >= 0 && (j == nums.size() || fabs((double)nums[i] - target) <= fabs((double)nums[j] - target))) {
            res.push_back(nums[i--]);
        }
        else {
            res.push_back(nums[j++]);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<int> res = closestKValues(root, 1.0, 1);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
