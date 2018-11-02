//
//  main.cpp
//  444. Sequence Reconstruction
//
//  Created by Jie Lu on 2018/8/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int n = (int)org.size();
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> inDegree(n + 1, 0);
    unordered_set<int> numsAppearInSeqs;
    
    for (auto seq : seqs) {
        for (auto a : seq) {
            numsAppearInSeqs.insert(a);
            if (a < 0 || a > n) {
                return false; // ensure all numbers in seqs are in proper range
            }
        }
    }
    
    if (numsAppearInSeqs.size() != n) {
        return false; // ensure every number in 1..n appears in seqs
    }
    
    for (auto seq : seqs) {
        if (seq.size() <= 1) {
            continue;
        }
        for (int i = 0; i < seq.size() - 1; i++) {
            graph[seq[i]].push_back(seq[i+1]);
            inDegree[seq[i+1]] += 1;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    if (q.size() > 1) {
        return false; // can't have more than one node whose indegree is zero. If so, there will be more than one supersequence
    }
    
    // use topological sort to get a sorted list
    vector<int> list;
    while (!q.empty()) {
        int thisNode = q.front();
        list.push_back(thisNode);
        q.pop();
        for (auto node : graph[thisNode]) {
            if (--inDegree[node] == 0) {
                q.push(node);
            }
        }
        if (q.size() > 1) {
            return false;
        }
    }
    
    // compare sorted list with org
    for (int i = 0; i < n; i++) {
        if (org[i] != list[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> org{1,2,3};
    vector<vector<int>> seqs{{1,2},{1,3},{2,3}};
    if (sequenceReconstruction(org, seqs)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
