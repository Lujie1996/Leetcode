//
//  main.cpp
//  947. Most Stones Removed with Same Row or Column
//
//  Created by Jie Lu on 2018/12/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<int,int> root;

int findSet(int node) {
    if (root.find(node) == root.end()) {
        root[node] = node;
    }
    else {
        while (root[node] != node) {
            node = root[node];
        }
    }
    return node;
}

void unionSet(int node1, int node2) {
    int p1 = findSet(node1);
    int p2 = findSet(node2);
    if (p1 != p2) {
        root[p2] = p1;
    }
}

// 用Union-Find把行和列连接起来
int removeStones(vector<vector<int>>& stones) {
    for (auto stone : stones) {
        unionSet(stone[0], ~stone[1]);
    }
    unordered_set<int> islands;
    for (auto stone : stones) {
        islands.insert(findSet(stone[0]));
    }
    return stones.size() - islands.size();
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> stones{{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<removeStones(stones)<<endl;
    return 0;
}
