//
//  main.cpp
//  44. Wildcard Matching
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// iterative without memoization. TLE in some test cases (940/1808) in Leetcode
//bool isMatch(string s, string p) {
//    if (s.length() == 0) {
//        if (p.length() == 0) {
//            return true;
//        }
//        for (auto c : p) {
//            if (c != '*') {
//                return false;
//            }
//        }
//        return true;
//    }
//    else {
//        if (p.length() == 0) {
//            return false;
//        }
//        if (p[0] == '*') {
//            return isMatch(s.substr(1), p) || isMatch(s, p.substr(1));
//        }
//        else {
//            if (p[0] == '?' || s[0] == p[0]) {
//                return isMatch(s.substr(1), p.substr(1));
//            }
//            else {
//                return false;
//            }
//        }
//    }
//}

// Iterative solution with memoization, also can be regarded as top-down DP. TLE in the last test case in leetcode
//bool isMatchHelper(vector<vector<int>>& match, string s, string p, int i, int j) {
//    if (s.size() == i && p.size() == j) {
//        return true;
//    }
//    if (s.size() != i && p.size() == j) {
//        return false;
//    }
//    if (match[i][j] != -1) {
//        return match[i][j] == 1;
//    }
//    if (p[j] != '*' && p[j] != '?') {
//        match[i][j] = s[i] == p[j] && isMatchHelper(match, s, p, i + 1, j + 1);
//        return match[i][j];
//    }
//    else if (p[j] == '?') {
//        if (i == s.size()) {
//            match[i][j] = 0;
//            return false;
//        }
//        match[i][j] = isMatchHelper(match, s, p, i + 1, j + 1);
//        return match[i][j];
//    }
//    else {
//        // p[j] == '*'
//        for (int k = i; k <= s.size(); k++) {
//            if (isMatchHelper(match, s, p, k, j + 1)) {
//                match[i][j] = 1;
//                return true;
//            }
//        }
//        match[i][j] = 0;
//        return false;
//    }
//}
//bool isMatch(string s, string p) {
//    vector<vector<int>> match(s.size()+1, vector<int>(p.size()+1, -1));
//    return isMatchHelper(match, s, p, 0, 0);
//}

// classical bottom-up DP, passed leetcode OJ
bool isMatch(string text, string pattern) {
    vector<vector<bool>> dp(text.size() + 1, vector<bool>(pattern.size() + 1));
    dp[text.size()][pattern.size()] = true;
    // dp(i, j): does text[i:] and pattern[j:] match?

    for (int i = (int)text.size(); i >= 0; i--){
        for (int j = (int)pattern.size() - 1; j >= 0; j--){
            bool first_match = (i < text.size() && (pattern[j] == text[i] || pattern[j] == '?' || pattern[j] == '*'));
            if (j < pattern.size() && pattern[j] == '*'){
                dp[i][j] = dp[i][j+1] || (first_match && dp[i+1][j]);
            }
            else {
                dp[i][j] = first_match && dp[i+1][j+1];
                cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
    }
    return dp[0][0];
}

// Very good solution from Discuss. But this idea is not general for similar problems.
//bool isMatch(string& str, string& pattern) {
//    int s = 0, p = 0, match = 0, starIdx = -1;
//    while (s < str.size()){
//        // advancing both pointers
//        if (p < pattern.size()  && (pattern[p] == '?' || str[s] == pattern[p])){
//            s++;
//            p++;
//        }
//        // * found, only advancing pattern pointer
//        else if (p < pattern.size() && pattern[p] == '*'){
//            starIdx = p; // use starIdx and match to record the already tried positions of s and p to handle *
//            match = s;
//            p++;
//        }
//        // last pattern pointer was *, advancing string pointer
//        else if (starIdx != -1){
//            p = starIdx + 1; // p retreats to original position if current s and p mismatch
//            match++;
//            s = match;
//        }
//        //current pattern pointer is not star, last patter pointer was not *
//        //characters do not match
//        else return false;
//    }
//
//    //check for remaining characters in pattern
//    while (p < pattern.size() && pattern[p] == '*')
//        p++;
//
//    return p == pattern.size();
//}


int main(int argc, const char * argv[]) {
//    string s = "mississippi";
//    string p = "m??*ss*?i*pi";
    string s = "ab";
    string p = "?*";
    if (isMatch(s, p)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
