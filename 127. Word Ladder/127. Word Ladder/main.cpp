//
//  main.cpp
//  127. Word Ladder
//
//  Created by Jie Lu on 2018/4/21.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
    unordered_set<string> visited;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    int pathLen = 1;
    q.push(beginWord);
    q.push("0");
    while(!q.empty()) {
        string qStr = q.front();
        q.pop();
        if (qStr == "0") {
            pathLen += 1;
            if (q.empty()) {
                return 0;
            }
            q.push("0");
            continue;
        }
        for (int i = 0; i < qStr.length(); i++) {
            string word = qStr;
            for (int j = 0; j <= 25; j++) {
                word[i] = 'a' + j;
                if (visited.find(word) == visited.end() && wordSet.find(word) != wordSet.end()) {
                    if (word == endWord) {
                        return pathLen + 1;
                    }
                    visited.insert(word);
                    q.push(word);
                }
            }
        }
    }
    return pathLen + 1;
}

int main(int argc, const char * argv[]) {
    string a[] = {"hot","dot","dog","lot","log","cog","cig","pig"};
    vector<string> wordList(a,a+8);
    cout<<ladderLength("hit", "cog", wordList)<<endl;
    return 0;
}


