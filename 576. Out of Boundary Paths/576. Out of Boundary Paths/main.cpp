//
//  main.cpp
//  576. Out of Boundary Paths
//
//  Created by Jie Lu on 2018/8/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 DP solution.
 dp[i][j]: the number of ways the position corresponding to the indices (i,j) can be reached given some particular number of moves.
 keep updating dp[i][j] in every move, in the meanwhile update count(对应于少于N次step就越过边界的情况)
 dp[i][j] = dp[i−1][j] + dp[i+1][j] + dp[i][j−1] + dp[i][j+1] Since current position might comes from four ajacent positions.
 note that we need a 'tmp dp' to keep updating the dp.
 */

// First version.
//int findPaths(int m, int n, int N, int i, int j) {
//    vector<vector<int>> dp(m, vector<int>(n, 0));
//    dp[i][j] = 1;
//    int count = 0, M = 1000000000 + 7;
//    for (int step = 0; step < N; step++) {
//        vector<vector<int>> tmp(m ,vector<int>(n, 0));
//        for (int x = 0; x < m; x++) {
//            for (int y = 0; y < n; y++) {
//                if (x == 0) {
//                    count = (count + dp[x][y]) % M;
//                }
//                if (x == m - 1) {
//                    count = (count + dp[x][y]) % M;
//                }
//                if (y == 0) {
//                    count = (count + dp[x][y]) % M;
//                }
//                if (y == n - 1) {
//                    count = (count + dp[x][y]) % M;
//                }
//                tmp[x][y] = x - 1 >= 0 ? (tmp[x][y] + dp[x-1][y]) % M : tmp[x][y];
//                tmp[x][y] = y - 1 >= 0 ? (tmp[x][y] + dp[x][y-1]) % M : tmp[x][y];
//                tmp[x][y] = x + 1 < m ? (tmp[x][y] + dp[x+1][y]) % M : tmp[x][y];
//                tmp[x][y] = y + 1 < n ? (tmp[x][y] + dp[x][y+1]) % M : tmp[x][y];
//            }
//        }
//        dp = tmp;
//    }
//    return count;
//}

// Reorganized the code, making it much cleaner
int findPaths(int m, int n, int N, int i, int j) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[i][j] = 1;
    int count = 0, M = 1000000000 + 7;
    vector<int> iMove{-1,0,1,0}, jMove{0,1,0,-1};
    for (int step = 0; step < N; step++) {
        vector<vector<int>> tmp(m ,vector<int>(n, 0));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                for (int a = 0; a < 4; a++) {
                    int nextX = x + iMove[a], nextY = y + jMove[a];
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                        tmp[nextX][nextY] = (tmp[nextX][nextY] + dp[x][y]) % M;
                    }
                    else {
                        count = (count + dp[x][y]) % M;
                    }
                }
            }
        }
        dp = tmp;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
