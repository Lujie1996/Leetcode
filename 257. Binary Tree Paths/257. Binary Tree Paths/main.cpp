//
//  main.cpp
//  257. Binary Tree Paths
//
//  Created by Jie Lu on 2018/5/7.
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

// Date: 2018/5/7
//void getPath(vector<string>& res, string cur, TreeNode* root) {
//    if (!root) {
//        return;
//    }
//    cur += to_string(root->val);
//    if (!root->left && !root->right) {
//        res.push_back(cur);
//        return;
//    }
//    cur += "->";
//    getPath(res, cur, root->left);
//    getPath(res, cur, root->right);
//}
//vector<string> binaryTreePaths(TreeNode* root) {
//    vector<string> res;
//    string cur = "";
//    getPath(res, cur, root);
//    return res;
//}

// Date: 2018/9/3
vector<string> binaryTreePaths(TreeNode * root) {
    // write your code here
    if (root == NULL) {
        return (vector<string>)NULL;
    }
    if (!root->left && !root->right) {
        vector<string> res;
        res.push_back(to_string(root->val));
        return res;
    }
    vector<string> leftRes = binaryTreePaths(root->left);
    vector<string> rightRes = binaryTreePaths(root->right);
    vector<string> res;
    string thisChar = to_string(root->val) + "->";
    for (auto s : leftRes) {
        res.push_back(thisChar + s);
    }
    for (auto s : rightRes) {
        res.push_back(thisChar + s);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<string> res = binaryTreePaths(root);
    for (string s : res) {
        cout<<s<<endl;
    }
    return 0;
}
