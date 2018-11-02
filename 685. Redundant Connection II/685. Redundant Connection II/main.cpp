//
//  main.cpp
//  685. Redundant Connection II
//
//  Created by Jie Lu on 2018/9/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// http://www.cnblogs.com/grandyang/p/8445733.html

int getRoot(vector<int>& root, int i) {
    return i == root[i] ? i : getRoot(root, root[i]);
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    vector<int> root(n + 1, 0), first, second;
    for (auto& edge : edges) {
        if (root[edge[1]] == 0) {
            root[edge[1]] = edge[0];
        }
        else {
            // 当edge[1]的root不为0，说明此前已经有一条边指向了edge[1]节点，那么当前的edge就是第二条指向edge[1]的节点
            first = {root[edge[1]], edge[1]}; // 第一条指向edge[1]的边
            second = edge; // 第二条指向edge[1]的边
            edge[1] = 0;
        }
    }
    for (int i = 0; i <= n; ++i)
        root[i] = i;
    for (auto& edge : edges) {
        if (edge[1] == 0)
            continue;
        int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
        if (x == y) // 存在环
            return first.empty() ? edge : first;
        root[x] = y;
    }
    return second;
}


int main(int argc, const char * argv[]) {
//    vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
//    vector<vector<int>> edges{{4,1},{4,5},{2,4},{5,3},{2,1}};
    vector<vector<int>> edges{{1,2}, {1,3}, {2,3}};
    vector<int> res = findRedundantDirectedConnection(edges);
    cout<<res[0]<<", "<<res[1]<<endl;
    return 0;
}
