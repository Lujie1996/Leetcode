//
//  main.cpp
//  297. Serialize and Deserialize Binary Tree
//
//  Created by Jie Lu on 2018/9/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
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

string serialize(TreeNode * root) {
    // write your code here
    if (!root) {
        return "()";
    }
    return "(" + to_string(root->val) + serialize(root->left) + serialize(root->right) + ")";
}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in
 * "serialize" method.
 */

string getString(string& data, int& i) {
    int start = i, count = 0;
    if (data[i] != '(') {
        return "";
    }
    
    // Doing a brackets matching, since there can be nesting brackets.
    // data[i] should points to the starting '(', use count to find its corresponding ')'
    while (i < data.size()) {
        if (data[i] == '(') {
            count++;
        }
        else if (data[i] == ')') {
            count--;
        }
        if (count == 0) {
            break;
        }
        i++;
    }
    i++;
    return data.substr(start, i - start);
}

TreeNode* deserialize(string data) {
    // write your code here
    if (data.size() == 0 || data.size() == 2) {
        // 0 for "" and 2 for "()"
        return NULL;
    }
    int i = 1; // pass the leading '('
    while (i < data.size() && (isdigit(data[i]) || data[i] == '-'))  {
        i++;
    }
    TreeNode* root = new TreeNode(stoi(data.substr(1, i)));
    string leftChild = getString(data, i);
    string rightChild = getString(data, i);
    root->left = deserialize(leftChild);
    root->right = deserialize(rightChild);
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root;
    createTree(root);
    string res = serialize(root);
    cout<<res<<endl;
    return 0;
}
