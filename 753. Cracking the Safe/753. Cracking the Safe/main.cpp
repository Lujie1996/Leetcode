//
//  main.cpp
//  753. Cracking the Safe
//
//  Created by Jie Lu on 2018/11/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool dfs(string& cur, unordered_set<string>& visited, int goal, int n, int k) {
    if (visited.size() == goal) {
        return true;
    }
    string pre = n > 1 ? cur.substr(cur.size()-n+1,n-1) : "";
    for (int i = 0; i < k; i++) {
        string thisTry = pre + to_string(i);
        if (visited.find(thisTry) == visited.end()) {
            visited.insert(thisTry);
            cur += to_string(i);
            if (dfs(cur, visited, goal, n, k)) {
                return true;
            }
            visited.erase(thisTry);
            cur.pop_back();
        }
    }
    return false;
}

string crackSafe(int n, int k) {
    string res;
    for (int i = 0; i < n; i++) {
        res += "0";
    }
    
    unordered_set<string> visited;
    visited.insert(res);
    
    int goal = (int)pow(k, n);
    dfs(res, visited, goal, n, k);
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<crackSafe(2, 2)<<endl;
    return 0;
}
