//
//  main.cpp
//  126. Word Ladder II
//
//  Created by Jie Lu on 2018/4/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//
/*
 This code is not correct.
 In this test case:
 "red"
 "tax"
 ["ted","tex","red","tax","tad","den","rex","pee"]
 It can not connect rex with tex since tex is visited.
 Wait to be modified...
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;

void getPath(vector<vector<string>>& res, map<string, vector<string>>& nextWords, vector<string> cur, string beginWord, string endWord) {
    if (beginWord == endWord) {
        res.push_back(cur);
        return;
    }
    if (nextWords[beginWord].size() == 0) {
        return;
    }
    for (string next : nextWords[beginWord]) {
        cur.push_back(next);
        getPath(res, nextWords, cur, next, endWord);
        cur.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
    unordered_set<string> visited;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> res;
    map<string, vector<string>> nextWords;
    q.push(beginWord);
    q.push("0");
    visited.insert(beginWord);
    while(!q.empty()) {
        string qStr = q.front();
        q.pop();
        if (qStr == "0") {
            if (q.empty()) {
                break;
            }
            q.push("0");
            continue;
        }
        for (int i = 0; i < qStr.length(); i++) {
            string word = qStr;
            for (int j = 0; j <= 25; j++) {
                word[i] = 'a' + j;
                if (visited.find(word) == visited.end() && wordSet.find(word) != wordSet.end()) {
                    if (word != endWord) {
                        visited.insert(word);
                        q.push(word);
                    }
                    nextWords[qStr].push_back(word);
                }
            }
        }
    }
    vector<string> cur;
    cur.push_back(beginWord);
    getPath(res, nextWords, cur, beginWord, endWord);
    int minPathLen = INT_MAX;
    int len;
    for (vector<string> path : res) {
        len = (int)path.size();
        minPathLen = len < minPathLen ? len : minPathLen;
    }
    for (int i = 0; i < res.size(); i++) {
        if (res[i].size() > minPathLen) {
            res.erase(res.begin() + i);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
//    string a[] = {"hot","dot","dog","lot","log","cog"};
    string a[] = {"a","b","c"};
    vector<string> words(a,a+3);
//    vector<vector<string>> res = findLadders("hit", "cog", words);
    vector<vector<string>> res = findLadders("a", "c", words);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
