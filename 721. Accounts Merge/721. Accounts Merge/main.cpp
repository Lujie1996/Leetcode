//
//  main.cpp
//  721. Accounts Merge
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

string find(string s, map<string, string>& p) {
    return p[s] == s ? s : find(p[s], p);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
    map<string, string> owner;
    map<string, string> parents;
    map<string, set<string>> unions;
    for (int i = 0; i < acts.size(); i++) {
        for (int j = 1; j < acts[i].size(); j++) {
            parents[acts[i][j]] = acts[i][j];
            owner[acts[i][j]] = acts[i][0];
        }
    }
    for (int i = 0; i < acts.size(); i++) {
        string p = find(acts[i][1], parents);
        for (int j = 2; j < acts[i].size(); j++)
            parents[find(acts[i][j], parents)] = p;
    }
    for (int i = 0; i < acts.size(); i++)
        for (int j = 1; j < acts[i].size(); j++)
            unions[find(acts[i][j], parents)].insert(acts[i][j]);
    
    vector<vector<string>> res;
    for (auto p : unions) {
        vector<string> emails(p.second.begin(), p.second.end());
        emails.insert(emails.begin(), owner[p.first]);
        res.push_back(emails);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
