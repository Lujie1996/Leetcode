//
//  main.cpp
//  1048. Longest String Chain
//
//  Created by Jie Lu on 2019/8/15.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSuccessor(string& a, string& b) {
    int i = 0;
    while (a[i] == b[i]) {
        i++;
    }
    return a.substr(i) == b.substr(i+1);
}

int dfs(unordered_map<string, vector<string>>& graph, string& start, unordered_map<string, int>& history) {
    if (graph.find(start) == graph.end()) {
        history[start] = 1;
        return 1;
    }
    if (history.find(start) != history.end()) {
        return history[start];
    }
    int maxLength = 0;
    for (auto next : graph[start]) {
        maxLength = max(maxLength, dfs(graph, next, history));
    }
    history[start] = maxLength++;
    return maxLength;
}

int longestStrChain(vector<string>& words) {
    unordered_map<int, vector<string>> lenWords;
    for (auto word : words) {
        lenWords[(int)word.size()].push_back(word);
    }
    unordered_map<string, vector<string>> graph;
    for (auto word : words) {
        int len = (int)word.size();
        for (auto nextWord : lenWords[len+1]) {
            if (isSuccessor(word, nextWord)) {
                graph[word].push_back(nextWord);
            }
        }
    }
    int res = 0;
    sort(words.begin(), words.end(), [](string& a, string& b){return a.size() < b.size();});
    for (auto w : words) {
        cout<<w<<"->";
        for (auto x : graph[w]) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    unordered_map<string, int> history;
    for (auto word : words) {
        int length = dfs(graph, word, history);
        res = max(res, length);
    }
    
    cout<<endl;
    for (auto row : history) {
        cout<<row.first<<" "<<row.second<<endl;
    }
    return res;
}



int main(int argc, const char * argv[]) {
    vector<string> words = {"sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz"};
    cout<<longestStrChain(words)<<endl;
    return 0;
}
