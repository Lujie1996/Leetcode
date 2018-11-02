//
//  main.cpp
//  133. Clone Graph
//
//  Created by Jie Lu on 2018/8/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// BFS version
//UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//    if (node == nullptr) {
//        return nullptr;
//    }
//    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copyHash;
//    copyHash[node] = new UndirectedGraphNode(node->label);
//    queue<UndirectedGraphNode*> q;
//    q.push(node);
//    while (!q.empty()) {
//        UndirectedGraphNode* thisNode = q.front();
//        q.pop();
//        for (auto ajacentNode : thisNode->neighbors) {
//            if (copyHash.find(ajacentNode) == copyHash.end()) {
//                copyHash[ajacentNode] = new UndirectedGraphNode(ajacentNode->label);
//                q.push(ajacentNode);
//            }
//            copyHash[thisNode]->neighbors.push_back(copyHash[ajacentNode]);
//        }
//    }
//    return copyHash[node];
//}

// DFS version
UndirectedGraphNode* copyNode(unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& copyHash, UndirectedGraphNode* node) {
    if (copyHash.find(node) != copyHash.end()) {
        return copyHash[node];
    }
    UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
    copyHash[node] = res;
    for (auto ajacentNode : node->neighbors) {
        res->neighbors.push_back(copyNode(copyHash, ajacentNode));
    }
    return res;
}
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
        return nullptr;
    }
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copyHash;
    return copyNode(copyHash, node);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
