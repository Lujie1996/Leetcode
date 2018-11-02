//
//  main.cpp
//  207. Course Schedule
//
//  Created by Jie Lu on 2018/4/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/*
 Topological sorting, based on Kahn algorithm
 Psudocode:
     L ← Empty list that will contain the sorted elements
     S ← Set of all nodes with no incoming edge
     while S is non-empty do
        remove a node n from S
        add n to tail of L
        for each node m with an edge e from n to m do
            remove edge e from the graph
            if m has no other incoming edges then
                insert m into S
     if graph has edges then
        return error (graph has at least one cycle)
     else
        return L (a topologically sorted order)
 */

// My implementation, only beats 20%
//bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//    vector<int> inDegree(numCourses, 0);
//    for (pair<int, int> edge : prerequisites) {
//        inDegree[edge.second] += 1;
//    }
//    int totalErasedNode = 0;
//    unordered_set<int> erasedEdges;
//    while (true) {
//        if (totalErasedNode == numCourses) {
//            return true;
//        }
//        int countOfStartNode = 0;
//        for (int i = 0; i < numCourses; i++) {
//            if (inDegree[i] == 0) {
//                countOfStartNode += 1;
//                inDegree[i] = -1;
//                for (int j = 0; j < prerequisites.size(); j++) {
//                    if (prerequisites[j].first == i && erasedEdges.find(j) == erasedEdges.end()) {
//                        inDegree[prerequisites[j].second] -= 1;
//                        erasedEdges.insert(j);
//                    }
//                }
//            }
//        }
//        totalErasedNode += countOfStartNode;
//        if (countOfStartNode == 0) {
//            return false;
//        }
//    }
//}


//Another implementation from internet, beats 98%
// [x,y] : x <- y
// for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses,0);
    for(auto edge : prerequisites)
    {
        graph[edge.second].push_back(edge.first); // graph[i] contains all courses that take i as prerequisite
        ++indegree[edge.first];
        // 其实graph就是邻接表，map保存的是key的后续节点
    }
    queue<int> Q;
    for(int i = 0;i < numCourses;i++)
        if(indegree[i] == 0)
            Q.push(i);
    int counter = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ++counter;
        for(auto v : graph[u])
        {
            if(--indegree[v] == 0)
                Q.push(v);
        }
    }
    return counter == numCourses;
}

int main(int argc, const char * argv[]) {
    ve
    if (canFinish(5, prerequisites)) {
        cout<<"no loop"<<endl;
    }
    else
        cout<<"has loop"<<endl;
    return 0;
}
