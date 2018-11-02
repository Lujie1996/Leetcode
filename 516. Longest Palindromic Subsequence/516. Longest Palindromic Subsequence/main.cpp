//
//  main.cpp
//  516. Longest Palindromic Subsequence
//
//  Created by Jie Lu on 2018/7/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 dp[i][j]: the longest palindromic subsequence's length of substring(i, j), here i, j represent left, right indexes in the string
 State transition:
 dp[i][j] = dp[i+1][j-1] + 2 if s[i] == s[j]
 otherwise, dp[i][j] = max(dp[i+1][j], dp[i][j-1])
 Initialization: dp[i][i] = 1
 */
int longestPalindromeSubseq(string s) {
    int n = (int)s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
int main(int argc, const char * argv[]) {
    cout<<longestPalindromeSubseq("aabaa")<<endl;
    return 0;
}
