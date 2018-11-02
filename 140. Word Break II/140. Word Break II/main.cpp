//
//  main.cpp
//  140. Word Break II
//
//  Created by Jie Lu on 12/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> getCombi(string s, vector<bool> dp, unordered_set<string> dict, int tail){
    vector<string> res;
    if (tail == 0)
        return res;
    for (int i = tail-1; i >= 0; i--) {
        if (dp[i]) {
            string word = s.substr(i,tail-i);
            if (dict.find(word) != dict.end()){
                if (i == 0) {
                    res.push_back(word);
                }
                else {
                    vector<string> tmp = getCombi(s, dp, dict, i);
                    for(int j = 0; j < tmp.size(); j++){
                        res.push_back(tmp[j] + " " + word);
                    }
                }
            }
        }
    }
    return res;
}
vector<string> wordBreak(string s, vector<string>& wordDict){
    vector<string> res;
    if (wordDict.size() == 0) {
        return res;
    }
    unordered_set<string> dict{wordDict.begin(), wordDict.end()};
    vector<bool> dp(s.size() + 1, false);
    // dp[i] == true 表示 s.substr(0,i-1) 可以被完美划分
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (dp[j] && dict.find(s.substr(j,i-j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    if(!dp[s.size()])
        return res;
    return getCombi(s, dp, dict, (int)s.size());
}
int main(int argc, const char * argv[]) {
    string s = "catsanddog";
    vector<string> wordDict;
    wordDict.push_back("cat");
    wordDict.push_back("cats");
    wordDict.push_back("and");
    wordDict.push_back("sand");
    wordDict.push_back("dog");
    vector<string> res = wordBreak(s, wordDict);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
