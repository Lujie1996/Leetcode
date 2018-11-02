//
//  main.cpp
//  865. Smallest Subtree with all the Deepest Nodes
//
//  Created by Jie Lu on 2018/8/20.
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
//This is my original code. Used 20min and beats 100%.
//void dfs(TreeNode* root, TreeNode*& deepest, int& depth) {
//    if (!root->left && !root->right) {
//        deepest = root;
//        depth = 1;
//        return;
//    }
//    TreeNode *left = NULL, *right = NULL;
//    int depthLeft = 0, depthRight = 0;
//    if (root->left) {
//        dfs(root->left, left, depthLeft);
//    }
//    if (root->right) {
//        dfs(root->right, right, depthRight);
//    }
//    if (left && right) {
//        if (depthLeft > depthRight) {
//            deepest = left;
//            depth = depthLeft + 1;
//        }
//        else if (depthLeft < depthRight) {
//            deepest = right;
//            depth = depthRight + 1;
//        }
//        else {
//            deepest = root;
//            depth = depthLeft + 1;
//        }
//    }
//    else if (left) {
//        deepest = left;
//        depth = depthLeft + 1;
//    }
//    else {
//        deepest = right;
//        depth = depthRight + 1;
//    }
//}
//TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//    if (!root) {
//        return NULL;
//    }
//    TreeNode* deepest;
//    int depth = 1;
//    dfs(root, deepest, depth);
//    return deepest;
//}

// From discuss. Same idea. Much more simple in implementation.
pair<int, TreeNode*> f(TreeNode* root) {
    if (root == nullptr)
        return {0, root};
    
    auto l = f(root->left);
    auto r = f(root->right);
    
    if (l.first == r.first) {
        return {1 + l.first, root};
    }
    else if (l.first > r.first) {
        return {1 + l.first, l.second};
    }
    else {
        return {1 + r.first, r.second};
    }
}
pair<TreeNode*, int> dfs(TreeNode* root) {
    // C++语法 -- pair的初始化：
    pair<int, int> p = {1, 2};
    pair<int, int> q(1,2);
//    return make_pair(NULL, 0); // 编译报错
//    return make_pair((void*)NULL, 0); // 编译报错 void* X不能‘隐式’转换成其他指针类型的变量X，但是nullptr可以
    return make_pair((TreeNode*)NULL, 0);
    return make_pair(nullptr, 0); // C++11 invented nullptr to avoid such problem.
    // 用NULL初始化pair：https://stackoverflow.com/questions/18217221/c-cant-initialize-a-pointer-in-a-pair-to-null
    return {NULL, 0};
    // 原因：用NULL初始化，编译器先用NULL初始化一个long类型变量（GCC），再用它初始化TreeNode*。当然long不能转化成TreeNode*所以报错。
    // 用{NULL, 0} 就可以，原因是NULL没有先被初始化成long类型，而是直接用NULL初始化TreeNode*。
    // C++11 的关键字 nullptr 是指针字面常量，它可以被隐式转换到任意指针类型。
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return f(root).second;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    TreeNode* res = subtreeWithAllDeepest(root);
    cout<<res->val<<endl;
    return 0;
}
