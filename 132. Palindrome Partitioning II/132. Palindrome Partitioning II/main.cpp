//
//  main.cpp
//  132. Palindrome Partitioning II
//
//  Created by Jie Lu on 2018/4/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//
/*
    palindrome problems usually traverse in an expansion way : s[i-j], s[i+j]
    dp solution works in this way: expand from center s[i], while the palindrome substr keep growing to both sides,
    untill it reaches the boundary or disturbed, then update dp[i+j+i] according to min(dp[i+j+1], dp[i-j]+1);
    Why use dp[i+j+1] to denote s[0..i+j]? Think of "aba", if dp[i+j] includes the right boundary, then you cannot
    compare dp[0]+1 and dp[i+j], since dp[0] inclues 'a', here we need to present dp as it excludes dp[i-j].
 */

#include <iostream>
#include <vector>
using namespace std;
int minCut(string s) {
    int n = (int)s.length();
    vector<int> dp(n+1, 0); // number of cuts for the first k characters
    for (int i = 0; i <= n; i++) {
        dp[i] = i - 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; i + j < n && i - j >= 0 && s[i-j] == s[i+j]; j++) {
            dp[i+j+1] = min(dp[i+j+1], dp[i-j] + 1);
        }
        for (int j = 1; i + j < n && i - j + 1>= 0 && s[i-j+1] == s[i+j]; j++) {
            dp[i+j+1] = min(dp[i+j+1], dp[i-j+1] + 1);
        }
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    cout<<minCut("ababa")<<endl;
    return 0;
}
