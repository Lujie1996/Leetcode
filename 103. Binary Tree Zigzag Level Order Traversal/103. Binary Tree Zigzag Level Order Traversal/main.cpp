//
//  main.cpp
//  103. Binary Tree Zigzag Level Order Traversal
//
//  Created by Jie Lu on 2018/4/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
//vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//    queue<TreeNode*> q;
//    q.push(root);
//    q.push(NULL);
//    vector<vector<int>> res;
//    vector<TreeNode*> row;
//    int rowNo = 1;
//    TreeNode* thisNode = q.front();
//    if (!root) {
//        return res;
//    }
//    while (q.size() > 1) {
//        while (thisNode != NULL) {
//            row.push_back(thisNode);
//            if (thisNode->left) {
//                q.push(thisNode->left);
//            }
//            if (thisNode->right) {
//                q.push(thisNode->right);
//            }
//            q.pop();
//            thisNode = q.front();
//        }
//        q.push(NULL);
//        q.pop();
//        thisNode = q.front();
//        if (rowNo % 2 == 0) {
//            reverse(row.begin(), row.end());
//        }
//        vector<int> rowData((int)row.size(), 0);
//        for (int i = 0; i < row.size(); i++) {
//            rowData[i] = row[i]->val;
//        }
//        row.clear();
//        res.push_back(rowData);
//        rowNo += 1;
//    }
//    return res;
//}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> bfs;
    vector<int> resThisLevel;
    bfs.push(root);
    bfs.push(NULL);
    TreeNode* thisNode;
    int rowNo = 1;
    while (!bfs.empty()) {
        thisNode = bfs.front();
        bfs.pop();
        if (thisNode == NULL) {
            if (rowNo % 2 == 0) {
                reverse(resThisLevel.begin(), resThisLevel.end());
            }
            rowNo += 1;
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
    vector<vector<int>> res = zigzagLevelOrder(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
