//
//  main.cpp
//  562. Longest Line of Consecutive One in Matrix
//
//  Created by Jie Lu on 2018/10/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int longestLine(vector<vector<int>>& M) {
    if (M.size() == 0) {
        return 0;
    }
    int m = (int)M.size(), n = (int)M[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // look to left
    int maxLen = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1) {
                dp[i][j] = 1;
            }
            if (j - 1 >= 0 && M[i][j-1] == 1) {
                dp[i][j] += dp[i][j-1];
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    
    // look to up
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (M[i][j] == 1) {
                dp[i][j] = 1;
            }
            if (i - 1 >= 0 && M[i-1][j] == 1) {
                dp[i][j] += dp[i-1][j];
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    
    // look to upper-left
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (M[i][j] == 1) {
                dp[i][j] = 1;
            }
            if (i - 1 >= 0 && j - 1 >= 0 && M[i-1][j-1] == 1) {
                dp[i][j] += dp[i-1][j-1];
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    
    // look to upper right
    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (M[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (M[i][j] == 1) {
                dp[i][j] = 1;
            }
            if (j + 1 < n && i - 1 >= 0 && M[i-1][j+1] == 1) {
                dp[i][j] += dp[i-1][j+1];
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> M{{0,1,1,0},{0,1,1,0},{0,0,0,1}};
    cout<<longestLine(M)<<endl;
    return 0;
}
