//
//  main.cpp
//  256. Paint House
//
//  Created by Jie Lu on 2018/6/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Input data can be viewed as a matrix. E.g. [[17,2,17],[16,16,5],[14,3,19]]
 [17,2,17]
 [16,16,5]
 [14,3,19]
 The problem is very similary to N Queen problem.
 From bottom to top, we need to find a path which has a smallest sum.
 dp[i][j]: Minimum sum on path ending at costs[i][j], inclusively.
 dp[1][2] = 8, since it's the min of 5 + 14 and 5 + 3.
 */

int helper(vector<vector<int>>& costs, vector<vector<int>>& dp, int row, int no) {
    if (row == dp.size() - 1) {
        return costs[row][no];
    }
    int minCost = INT_MAX;
    for (int i = 0; i < costs[0].size(); i++) {
        if (i == no) {
            continue;
        }
        minCost = min(minCost, dp[row + 1][i] + costs[row][no]);
    }
    return minCost;
}
int minCost(vector<vector<int>>& costs) {
    if (costs.size() == 0) {
        return 0;
    }
    int m = (int)costs.size(), n = (int)costs[0].size(),  res = INT_MAX;
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = helper(costs, dp, i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        res = min(res, dp[0][i]);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a{17,2,17}, b{16,16,5}, c{14,3,19};
    vector<vector<int>> costs{a, b, c};
    cout<<minCost(costs)<<endl;
    return 0;
}
