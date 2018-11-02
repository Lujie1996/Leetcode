//
//  main.cpp
//  688. Knight Probability in Chessboard
//
//  Created by Jie Lu on 2018/8/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

double knightProbability(int N, int K, int r, int c) {
    vector<vector<double>> dp(N, vector<double>(N, 0));
    dp[r][c] = 1;
    vector<int> iMove{-2,-2,-1,-1,1,1,2,2}, jMove{-1,1,-2,2,-2,2,-1,1};
    for (int step = 0; step < K; step++) {
        vector<vector<double>> tmp(N,vector<double>(N, 0));
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                for (int a = 0; a < 8; a++) {
                    int nextX = x+iMove[a], nextY = y+jMove[a];
                    if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                        tmp[nextX][nextY] += dp[x][y] / 8.0;
                    }
                }
            }
        }
        dp = tmp;
    }
    double res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res += dp[i][j];
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<knightProbability(3, 2, 0, 0)<<endl;
    return 0;
}
