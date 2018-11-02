//
//  main.cpp
//  428. Serialize and Deserialize N-ary Tree
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Encodes a tree to a single string.
string serialize(Node* root) {
    if (root == NULL) {
        return "";
    }
    string res = "(";
    res += to_string(root->val);
    for (auto& son : root->children) {
        res += serialize(son);
    }
    res += ")";
    return res;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    if (data == "") {
        return NULL;
    }
    int indexOfSecondLeftBracket = data.find('(',1);
    if (indexOfSecondLeftBracket == -1) {
        int val = stoi(data.substr(1, data.size()-1));
        return new Node(val);
    }
    
    int val = stoi(data.substr(1, indexOfSecondLeftBracket - 1));
    Node* root = new Node(val);
    
    int i = indexOfSecondLeftBracket, pre = i, count = 0;
    while (i < data.size()) {
        if (data[i] == '(') {
            count++;
        }
        else if (data[i] == ')') {
            count--;
        }
        if (count == 0) {
            string t = data.substr(pre, i - pre + 1);
            root->children.push_back(deserialize(t));
            pre = i + 1;
        }
        i++;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
