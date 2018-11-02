//
//  main.cpp
//  343. Integer Break
//
//  Created by Jie Lu on 2018/7/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j]*dp[i-j]);
        }
        dp[i] = max(dp[i], i);
        // note than when i == 2 or 3, dp[i] is smaller than i
        // doing this is for the benefit of computing dp[i] where i > 3
    }
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    cout<<integerBreak(10)<<endl;
    return 0;
}
