//
//  main.cpp
//  199. Binary Tree Right Side View
//
//  Created by Jie Lu on 2018/4/28.
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

// BFS; scan the tree by layer; implemented with queue; get the last element of every layer.
// Beat 100% C++ solutions
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    TreeNode *thisNode = root, *preNode = root;
    while (!q.empty()) {
        thisNode = q.front();
        q.pop();
        if (thisNode == NULL) {
            res.push_back(preNode->val);
            if (q.empty()) {
                break;
            }
            q.push(NULL);
        }
        else {
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
        preNode = thisNode;
    }
    return res;
}

// Other smart solution using recursion:
// Idea: every layer must contribute one element. If no element is picked until now (if(res.size()<level)), just pick present one.
//void recursion(TreeNode *root, int level, vector<int> &res)
//{
//    if(root==NULL) return ;
//    if(res.size()<level) res.push_back(root->val);
//    recursion(root->right, level+1, res);
//    recursion(root->left, level+1, res);
//}
//
//vector<int> rightSideView(TreeNode *root) {
//    vector<int> res;
//    recursion(root, 1, res);
//    return res;
//}

int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<int> res = rightSideView(root);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
