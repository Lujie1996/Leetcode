//
//  main.cpp
//  935. Knight Dialer
//
//  Created by Jie Lu on 2018/11/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int knightDialer(int N) {
    int M = 1000000007;
    vector<vector<int>> dp(N+1,vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }
    
    vector<vector<int>> preDigits{{4,6},{6,8},{7,9},{4,8},{0,3,9},{-1},{0,1,7},{2,6},{1,3},{2,4}};
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (auto pre : preDigits[j]) {
                if (pre != -1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][pre]) % M;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res = (res + dp[N][i]) % M;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
