//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by Jie Lu on 2018/9/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 DP solution
 
 dp[i]: the longest valid parenthesis which ends with s[i]
 
 if (s[i] == ')' && s[i-1] == '(')
    dp[i] = dp[i-2] + 2;
 if (s[i] == ')' && s[i-1] == ')' && s[i-dp[i-1]-1] == '(')
    dp[i] = dp[i-1] + d[i-dp[i-1]-2] + 2;
 if (s[i] == '(')
    dp[i] = 0;
 */
int longestValidParentheses(string s) {
    if (s.size() == 0) {
        return 0;
    }
    
    vector<int> dp(s.size(), 0);
    dp[0] = 0;
    
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            if (s[i-1] == '(') {
                dp[i] = dp[i-2] + 2;
            }
            else {
                if (s[i-dp[i-1]-1] == '(') {
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                }
                else {
                    dp[i] = 0;
                }
            }
        }
        else {
            dp[i] = 0;
        }
        res = max(res, dp[i]);
        cout<<i<<" "<<dp[i]<<endl;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<longestValidParentheses(")()())()()(")<<endl;
    return 0;
}
