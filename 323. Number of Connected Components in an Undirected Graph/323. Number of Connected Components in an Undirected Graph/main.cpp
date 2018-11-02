//
//  main.cpp
//  323. Number of Connected Components in an Undirected Graph
//
//  Created by Jie Lu on 2018/6/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findSet(vector<int>& parent, int node) {
    if (parent[node] == -1) {
        return node;
    }
    return findSet(parent, parent[node]);
}
void unionSet(vector<int>& parent, int node1, int node2) {
    int p1 = findSet(parent, node1), p2 = findSet(parent, node2);
    if (p1 != p2) {
        parent[p1] = p2;
    }
}
int countComponents(int n, vector<pair<int, int>>& edges) {
    vector<int> parent(n, -1);
    for (auto edge : edges) {
        if (findSet(parent, edge.first) != findSet(parent, edge.second)) {
            unionSet(parent, edge.first, edge.second);
        }
    }
    int res = 0;
    for (auto p : parent) {
        if (p == -1) {
            res++;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // [0, 1], [1, 2], [2, 3], [3, 4]
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 4));
    cout<<countComponents(5, edges)<<endl;
    return 0;
}
