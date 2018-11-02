//
//  main.cpp
//  746. Min Cost Climbing Stairs
//
//  Created by Jie Lu on 2018/7/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//int minCostClimbingStairs(vector<int>& cost) {
//    int n = (int)cost.size();
//    vector<int> dp(n, 0);
//    dp[0] = cost[0];
//    dp[1] = cost[1];
//    for (int i = 2; i < n; i++) {
//        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
//    }
//    return min(dp[n-1], dp[n-2]);
//}

// O(1) space version
int minCostClimbingStairs(vector<int>& cost) {
    // b, a, c
    int a = 0, b, result = 0;
    for (int c : cost) {
        b = a;
        a = c + result; // a means the minCost to current stair c
        result = min(a, b);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
}
