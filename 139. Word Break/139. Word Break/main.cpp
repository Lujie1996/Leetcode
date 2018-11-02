//
//  main.cpp
//  139. Word Break
//
//  Created by Jie Lu on 11/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string> wordDict){
    if (wordDict.size() == 0) {
        return false;
    }
    unordered_set<string> dict{wordDict.begin(), wordDict.end()};
    vector<bool> dp(s.size()+1, false);
    //dp[i]==true表示s.substr(0,i-1)可以被完美划分
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++){
        for (int j = i - 1; j >= 0; j--){
            if (dp[j]){
                string word = s.substr(j, i-j);
                if (dict.find(word) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[s.size()];
}
int main(int argc, const char * argv[]) {
    string s = "leetcode";
    vector<string> wordDict;
    wordDict.push_back("leet");
    wordDict.push_back("code");
    if(wordBreak(s, wordDict))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
