//
//  main.cpp
//  582. Kill Process
//
//  Created by Jie Lu on 2018/9/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// My first solution. beats 29%.
vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    vector<int> res;
    
    queue<int> q;
    q.push(kill);
    
    unordered_map<int, vector<int>> children;
    for (int i = 0; i < pid.size(); i++) {
        children[ppid[i]].push_back(pid[i]);
    }
    
    while (!q.empty()) {
        int thisNode = q.front();
        q.pop();
        res.push_back(thisNode);
        for (auto child : children[thisNode]) {
            q.push(child);
        }
    }
    return res;
}



int main(int argc, const char * argv[]) {
    /*
     pid =  [1, 3, 10, 5]
     ppid = [3, 0, 5, 3]
     kill = 5
     */
    vector<int> pid{1, 3, 10, 5};
    vector<int> ppid{3, 0, 5, 3};
    vector<int> res = killProcess(pid, ppid, 5);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
