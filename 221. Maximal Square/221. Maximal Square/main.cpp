//
//  main.cpp
//  221. Maximal Square
//
//  Created by Jie Lu on 2018/5/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    int m = (int)matrix.size(), n = (int)matrix[0].size(), res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]: width of maximal square whose right-lower corner is at matrix[i-1][j-1]
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i-1][j-1] == '1') {
                // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res * res;
}
int main(int argc, const char * argv[]) {
    /*
     1 0 1 0 0
     1 0 1 1 1
     1 1 1 1 1
     1 0 0 1 0
     */
    char a[] ={'1','0','1','0','0'}, b[] = {'1','0','1','1','1'}, c[] = {'1','1','1','1','1'}, d[] ={'1','0','0','1','0'};
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>(a, a + 5));
    matrix.push_back(vector<char>(b, b + 5));
    matrix.push_back(vector<char>(c, c + 5));
    matrix.push_back(vector<char>(d, d + 5));
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}
