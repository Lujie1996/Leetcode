//
//  main.cpp
//  684. Redundant Connection
//
//  Created by Jie Lu on 2018/9/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int findSet(vector<int>& root, int node) {
    while (root[node] != node) {
        node = root[node];
    }
    return node;
}
void unionSet(vector<int>& root, int node1, int node2) {
    int root1 = findSet(root, node1), root2 = findSet(root, node2);
    if (root1 != root2) {
        root[root1] = root2;
    }
}

// Idea: use union-find to detect the only loop. When loop is found, just return that edge. It should be the last removable edge.
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    vector<int> root(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        root[i] = i;
    }
    vector<int> res;
    for (auto edge : edges) {
        int node1 = edge[0], node2 = edge[1];
        if (findSet(root, node1) == findSet(root, node2)) {
            // loop found!
            res = edge;
            break;
        }
        else {
            unionSet(root, node1, node2);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> res = findRedundantConnection(edges);
    cout<<res[0]<<", "<<res[1]<<endl;
    return 0;
}
