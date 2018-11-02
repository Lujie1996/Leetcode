//
//  main.cpp
//  863. All Nodes Distance K in Binary Tree
//
//  Created by Jie Lu on 2018/10/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getLowerNodes(TreeNode* root, int cur, int K, vector<int>& res) {
    if (!root) {
        return;
    }
    if (cur == K) {
        res.push_back(root->val);
        return;
    }
    
    getLowerNodes(root->left, cur + 1, K, res);
    getLowerNodes(root->right, cur + 1, K, res);
}

int dfs(TreeNode* root, TreeNode* target, int K, vector<int>& res) {
    if (!root) {
        return -1;
    }
    
    if (root == target) {
        getLowerNodes(root, 0, K, res);
        return 1;
    }
    
    int d1 = dfs(root->left, target, K, res);
    int d2 = dfs(root->right, target, K, res);
    if (d1 != -1) {
        if (d1 == K) {
            res.push_back(root->val);
        }
        else if (d1 < K ) {
            getLowerNodes(root->right, d1+1, K, res);
        }
    }
    else if (d2 != -1) {
        if (d2 == K) {
            res.push_back(root->val);
        }
        else if (d2 < K ) {
            getLowerNodes(root->left, d2+1, K, res);
        }
    }
    
    return d1 != -1 ? d1 + 1 : (d2 != -1 ? d2+1 : -1);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    dfs(root, target, K, res);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
