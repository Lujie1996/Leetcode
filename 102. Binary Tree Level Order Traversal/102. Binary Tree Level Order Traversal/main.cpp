//
//  main.cpp
//  102. Binary Tree Level Order Traversal
//
//  Created by Jie Lu on 2018/4/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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
//vector<vector<int>> levelOrder(TreeNode* root) {
//    vector<vector<int>> res;
//    if (!root) {
//        return res;
//    }
//    queue<TreeNode*> bfs;
//    vector<int> resThisLevel;
//    bfs.push(root);
//    TreeNode* thisNode;
//    int totalOfThisLevel = 1, totalOfNextLevel = 2, count = 0;
//    while (!bfs.empty()) {
//        thisNode = bfs.front();
//        bfs.pop();
//        resThisLevel.push_back(thisNode->val);
//        if (!thisNode->left)
//            totalOfNextLevel -= 1;
//        else
//            bfs.push(thisNode->left);
//        if (!thisNode->right)
//            totalOfNextLevel -= 1;
//        else
//            bfs.push(thisNode->right);
//        count++;
//        if (count == totalOfThisLevel) {
//            res.push_back(resThisLevel);
//            resThisLevel.clear();
//            count = 0;
//            totalOfThisLevel = totalOfNextLevel;
//            totalOfNextLevel = 2 * totalOfThisLevel;
//        }
//    }
//    return res;
//}
// 一种更好的方法，不需要通过计数来看是否读取完一层。
// 采用每层添加唯一一个NULL节点的方法，用NULL节点将层与层之间分割开来
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> bfs;
    vector<int> resThisLevel;
    bfs.push(root);
    bfs.push(NULL);
    TreeNode* thisNode;
    while (!bfs.empty()) {
        thisNode = bfs.front();
        bfs.pop();
        if (thisNode == NULL) {
            res.push_back(resThisLevel);
            resThisLevel.clear();
            if (!bfs.empty()) {
                bfs.push(NULL);
            }
        }
        else {
            resThisLevel.push_back(thisNode->val);
            if (thisNode->left) {
                bfs.push(thisNode->left);
            }
            if (thisNode->right) {
                bfs.push(thisNode->right);
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<vector<int>> res = levelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
