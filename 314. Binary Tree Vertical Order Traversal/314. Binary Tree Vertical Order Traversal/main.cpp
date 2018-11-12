//
//  main.cpp
//  314. Binary Tree Vertical Order Traversal
//
//  Created by Jie Lu on 2018/11/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

void dfs(map<int, vector<pair<int,int>>>& colRes, int row, int col, TreeNode* root) {
    if (!root) {
        return;
    }
    colRes[col].push_back({row, root->val});
    dfs(colRes, row+1, col-1, root->left);
    dfs(colRes, row+1, col+1, root->right);
}

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    
    map<int, vector<pair<int,int>>> colRes;
    
    vector<pair<int,int>> col{{0,root->val}};
    colRes[0] = col;
    dfs(colRes, 0, -1, root->left);
    dfs(colRes, 0, 1, root->right);
    
    for (auto row : colRes) {
        sort(row.second.begin(), row.second.end(), [](const pair<int,int>& a, const pair<int,int>& b) {return a.first < b.first;});
        vector<int> tmp;
        for (auto p : row.second) {
            tmp.push_back(p.second);
        }
        res.push_back(tmp);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
