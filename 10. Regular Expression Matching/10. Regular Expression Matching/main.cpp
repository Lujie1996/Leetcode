//
//  main.cpp
//  10. Regular Expression Matching
//
//  Created by Jie Lu on 2018/9/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// iterative without memoization, beats 12% (farily slow)
// Comparing with a very similar problem LC44 Wildcard Matching, using this idea with not get passed for all test cases
// The reason might be that the test cases in this problem is less retrict and complex than LC44
// Anyway, it's better to use the top-down version DP, which is OK for both problems.
//bool isMatch(string s, string p) {
//    if (s.length() == 0) {
//        // s串匹配完合法的情况只有：p为空，或是 "X*X*"的形式
//        if (p.length() & 1) {
//            return false;
//        }
//        else {
//            for (int i = 1; i < p.length(); i += 2) {
//                if (p[i] != '*') {
//                    return false;
//                }
//            }
//            return true;
//        }
//    }
//    else {
//        if (p.length() == 0) {
//            return false;
//        }
//        if (p.length() > 1 && p[1] == '*') {
//            // p: X*....
//            if (p[0] == '.' || s[0] == p[0]) {
//                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
//            }
//            else {
//                return isMatch(s, p.substr(2));
//            }
//        }
//        else {
//            if (p[0] == '.' || s[0] == p[0]) {
//                return isMatch(s.substr(1), p.substr(1));
//            }
//            else {
//                return false;
//            }
//        }
//    }
//}

// bottom-up DP
bool isMatch(string text, string pattern) {
    vector<vector<bool>> dp(text.length() + 1, vector<bool>(pattern.length() + 1));
    dp[text.length()][pattern.length()] = true;
    // dp(i, j): does text[i:] and pattern[j:] match?
    
    for (int i = (int)text.length(); i >= 0; i--){
        for (int j = (int)pattern.length() - 1; j >= 0; j--){
            bool first_match = (i < text.length() && (pattern[j] == text[i] || pattern[j] == '.'));
            if (j + 1 < pattern.length() && pattern[j+1] == '*'){
                dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                // dp[i][j] = dp[i][j+2]: pass over X*
                // first_match && dp[i+1][j]: s[i] matches p[j] and try s[i+1:] match with p[j]
            }
            else {
                dp[i][j] = first_match && dp[i+1][j+1];
            }
        }
    }
    return dp[0][0];
}

int main(int argc, const char * argv[]) {
    string s = "mississippi";
    string p = "mis*is*p*";
    if (isMatch(s, p)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
