//
//  main.cpp
//  269. Alien Dictionary
//
//  Created by Jie Lu on 2018/11/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool getOneEdge(pair<char, char>& res, const string& word1, const string& word2) {
    int i = 0;
    while (i < word1.size() && i < word2.size()) {
        if (word1[i] == word2[i]) {
            i++;
        }
        else {
            res = {word1[i], word2[i]};
            return true;
        }
    }
    return false;
}

string alienOrder(vector<string>& words) {
    if (words.size() == 0) {
        return "";
    }
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> inDegree;
    
    // construct the graph
    for (int i = 0; i < words.size()-1; i++) {
        if (words[i] == words[i+1]) {
            continue;
        }
        pair<char, char> e;
        if (getOneEdge(e, words[i], words[i+1])) {
            graph[e.first].push_back(e.second);
            inDegree[e.second] += 1;
            if (inDegree.find(e.first) == inDegree.end()) {
                inDegree[e.first] = 0;
            }
        }
    }
    
    queue<char> startNodeQ;
    string res;
    
    // find start nodes
    for (auto row : inDegree) {
        if (row.second == 0) {
            startNodeQ.push(row.first);
        }
    }
    
    // run topological sort
    while (!startNodeQ.empty()) {
        char startNode = startNodeQ.front();
        startNodeQ.pop();
        res += startNode;
        for (auto next : graph[startNode]) {
            if (--inDegree[next] == 0) {
                startNodeQ.push(next);
            }
        }
    }
    
    if (res.size() == inDegree.size()) {
        // get charSet
        unordered_set<char> charSet;
        for (auto word : words) {
            for (auto c : word) {
                charSet.insert(c);
            }
        }
        
        // get the diff between inDegree and charSet.
        // The result is the letters that we cannot tell their order in dictionary
        string t = "";
        for (auto c : charSet) {
            if (inDegree.find(c) == inDegree.end()) {
                t += c;
            }
        }
        return t + res;
    }
    else {
        // there is a conflict! cannot build a dictionary
        return "";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
