//
//  main.cpp
//  508. Most Frequent Subtree Sum
//
//  Created by Jie Lu on 2018/8/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
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
        t = (TreeNode*)malloc(sizeof(TreeNode));
        t->val = ch-'0';
        createTree(t->left);
        createTree(t->right);
    }
}
int getSum(unordered_map<int, int>& sumCount, TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int thisSum = getSum(sumCount, root->left) + getSum(sumCount, root->right) + root->val
    ;
    sumCount[thisSum] += 1;
    return thisSum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    if (root == NULL) {
        return res;
    }
    unordered_map<int, int> sumCount;
    getSum(sumCount, root);
    int freqSumCount = 0;
    for (auto t : sumCount) {
        if (t.second > freqSumCount) {
            freqSumCount = t.second;
        }
    }
    for (auto t : sumCount) {
        if (t.second == freqSumCount) {
            res.push_back(t.first);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    vector<int> res = findFrequentTreeSum(root);
    for (auto i : res) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
