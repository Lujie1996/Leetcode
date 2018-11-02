//
//  main.cpp
//  95. Unique Binary Search Trees II
//
//  Created by Jie Lu on 2018/4/16.
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
vector<TreeNode*> getNodes(int start, int end) {
    vector<TreeNode*> res;
    if (start > end) {
        res.push_back(NULL);
        return res;
    }
    if (start == end) {
        res.push_back(new TreeNode(start));
        return res;
    }
    vector<TreeNode*> left, right;
    for (int i = start; i <= end; i++) {
        left = getNodes(start, i - 1);
        right = getNodes(i + 1, end);
        for (auto lnode : left) {
            for (auto rnode : right) {
                TreeNode* root = new TreeNode(i);
                root->left = lnode;
                root->right = rnode;
                res.push_back(root);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if (n == 0) {
        return res;
    }
    return getNodes(1, n);
}
int main(int argc, const char * argv[]) {
    vector<TreeNode*> res = generateTrees(0);
    for (int i = 0; i < res.size(); i++) {
        showTree(res[i]);
        cout<<endl;
    }
    return 0;
}
