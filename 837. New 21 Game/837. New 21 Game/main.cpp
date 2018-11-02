//
//  main.cpp
//  837. New 21 Game
//
//  Created by Jie Lu on 2018/10/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

double new21Game(int N, int K, int W) {
    if (K == 0) {
        return 1.0;
    }
    
    vector<double> dp(N+1, 0);
    dp[0] = 1.0;
    double sum = 1.0;
    for (int i = 1; i <= N; i++) {
        dp[i] = sum / W;
        if (i < K) {
            sum += dp[i];
        }
        if (i - W >= 0 && i - W < K) {
            sum -= dp[i-W];
        }
    }
    double res = 0;
    for (int i = K; i <= N; i++) {
        res += dp[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
