//
//  main.cpp
//  395. Longest Substring with At Least K Repeating Characters
//
//  Created by Jie Lu on 2018/7/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Recursive version.
// The main idea is to get isThisCharLessThanK vector, and try all substrings  sliced by this vector through calling itself.
int longestSubstring(string s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, vector<int>> charIndex;
    for (int i = 0; i < s.size(); i++) {
        charIndex[s[i]].push_back(i);
    }
    vector<bool> isThisCharLessThanK(s.size());
    bool hasLessThanK = false;
    for (auto a : charIndex) {
        if (a.second.size() < k) {
            hasLessThanK = true;
            for (auto index : a.second) {
                isThisCharLessThanK[index] = true;
            }
        }
    }
    if (hasLessThanK == false) {
        return (int)s.size();
    }
    int res = 0, preIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        while (i < s.size() && isThisCharLessThanK[i] == false) {
            i++;
        }
        res = max(res, longestSubstring(s.substr(preIndex, i - preIndex), k));
        preIndex = i + 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<longestSubstring("abcdedghijklmnopqrstuvwxyz", 2)<<endl;
    cout<<longestSubstring("ababbc", 2)<<endl;
    return 0;
}
