//
//  main.cpp
//  210. Course Schedule II
//
//  Created by Jie Lu on 2018/4/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    vector<int> res;
    for (auto edge : prerequisites) {
        graph[edge.second].push_back(edge.first);
        indegree[edge.first] += 1;
    }
    queue<int> Q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    int count = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        res.push_back(u);
        count += 1;
        for (auto v : graph[u]) {
            if (--indegree[v] == 0) {
                Q.push(v);
            }
        }
    }
    return count == numCourses ? res : vector<int>();
}
int main(int argc, const char * argv[]) {
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(0, 1));
    prerequisites.push_back(make_pair(1, 2));
    prerequisites.push_back(make_pair(2, 3));
    prerequisites.push_back(make_pair(3, 4));
    prerequisites.push_back(make_pair(4, 3));
    vector<int> res = findOrder(5, prerequisites);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
