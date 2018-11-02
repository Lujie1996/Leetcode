//
//  main.cpp
//  261. Graph Valid Tree
//
//  Created by Jie Lu on 2018/6/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 The graph is a tree only if 1.there does not exist a loop and 2.there is no lonely node(not connected to any other node);
 1. To detect a loop, use Union-Find algorithm. Iterate edges and union both nodes of an edge.
    Before union any two nodes, check if they already have a common root. If so, there must a loop.
 2. If there isn't a lonely node, then the root of the tree must be the only node which have itself as its parent.
    So, iterate the parent vector to check if there is only one node whose parent is itself.
 */
int findSet(const vector<int>& parent, int node) {
    if (parent[node] == -1) {
        return node;
    }
    return findSet(parent, parent[node]);
}
void unionSet(vector<int>& parent, int node1, int node2) {
    int p1 = findSet(parent, node1);
    int p2 = findSet(parent, node2);
    if (p1 == p2) {
        return;
    }
    parent[p2] = p1;
}
bool existLoop(vector<vector<int>>& e, vector<int>& parent) {
    for (int i = 0; i < e.size(); i++) {
        for (int j = 0; j < e[i].size(); j++) {
            if (findSet(parent, i) == findSet(parent, e[i][j])) {
                return true;
            }
            else {
                unionSet(parent, i, e[i][j]);
            }
        }
    }
    return false;
}
bool existLonelyNode(vector<int>& parent) {
    int count = 0;
    for (int i = 0; i < parent.size(); i++) {
        if (parent[i] == -1) {
            count++;
        }
    }
    return count != 1;
}
bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<int> parent(n, -1);
    vector<vector<int>> e(n, vector<int>(0, 0));
    for (auto edge : edges) {
        e[edge.first].push_back(edge.second);
    }
    if (!existLoop(e, parent) && !existLonelyNode(parent)) {
        return true;
    }
    else {
        return false;
    }
}
int main(int argc, const char * argv[]) {
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(0, 2));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 4));
//    edges.push_back(make_pair(1, 2));
    if (validTree(6, edges)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
