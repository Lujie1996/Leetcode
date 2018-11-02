//
//  main.cpp
//  115. Distinct Subsequences
//
//  Created by Jie Lu on 2018/9/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// dp[i][j]: the number of distinct sequence in t[0..i] which equals to s[0..j-1]
// if s[i-1] != t[j-1]: dp[i][j] = dp[i][j-1]
// if s[i-1] == t[j-1]: dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
int numDistinct(string s, string t) {
    int m = (int)t.size(), n = (int)s.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1;
        // The initialization comes from the expr: dp[i][j] = dp[i][j-1] + (s[j-1] == t[i-1] ? dp[i-1][j-1] : 0);
        // dp[i-1][j-1] should make sure to be 1 when i-1 == 0. Consider s[j-1] == t[i-1], dp[i][j] should be equal to dp[i][j-1] + 1
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1] + (s[j-1] == t[i-1] ? dp[i-1][j-1] : 0);
            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    return dp[m][n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<numDistinct("babgbag", "bag")<<endl;
    return 0;
}
