//
//  main.cpp
//  399. Evaluate Division
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool dfs(unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string> visited, string start, string end, double& res) {
    if (start == end) {
        return true;
    }
    visited.insert(start);
    for (auto pair : graph[start]) {
        string next = pair.first;
        if (visited.find(next) == visited.end()) {
            double cur = res * pair.second;
            if (dfs(graph, visited, next, end, cur)) {
                res = cur;
                return true;
            }
        }
    }
    return false;
}

double compute(unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& allString, pair<string, string>& query) {
    string start = query.first, end = query.second;
    if (start == end && allString.find(start) != allString.end()) {
        return 1.0;
    }
    if (allString.find(start) == allString.end() || allString.find(start) == allString.end()) {
        return -1.0;
    }
    double res = 1;
    unordered_set<string> visited;
    return dfs(graph, visited, start, end, res) ? res : -1;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    vector<double> res;
    
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_set<string> allString;
    for (int i = 0; i < equations.size(); i++) {
        allString.insert(equations[i].first);
        allString.insert(equations[i].second);
        graph[equations[i].first].push_back({equations[i].second, values[i]});
        graph[equations[i].second].push_back({equations[i].first, 1.0 / values[i]});
    }
    
    for (auto q : queries) {
        res.push_back(compute(graph, allString, q));
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
//    vector<pair<string, string>> equations{{"a","b"},{"b","c"}};
//    vector<double> values{2.0, 3.0};
//    vector<pair<string, string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    
    vector<pair<string, string>> equations{{"a","b"}};
    vector<double> values{0.5};
    vector<pair<string, string>> queries{{"b","a"}};
    
    vector<double> res = calcEquation(equations, values, queries);
    for (auto x : res) {
        cout<<x<<endl;
    }
    return 0;
}
