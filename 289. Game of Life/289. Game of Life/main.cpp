//
//  main.cpp
//  289. Game of Life
//
//  Created by Jie Lu on 2018/7/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// My original solution. The verbose if clauses are very ugly...
//void gameOfLife(vector<vector<int>>& board) {
//    int m = (int)board.size(), n = (int)board[0].size();
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            int count = 0;
//            if (i > 0) {
//                // up row
//                if (j > 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == -1)) {
//                    count++;
//                }
//                if (board[i-1][j] == 1 || board[i-1][j] == -1) {
//                    count++;
//                }
//                if (j + 1 < n && (board[i-1][j+1] == 1 || board[i-1][j+1] == -1)) {
//                    count++;
//                }
//            }
//            if (i + 1 < m) {
//                // down row
//                if (j > 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == -1)) {
//                    count++;
//                }
//                if (board[i+1][j] == 1 || board[i+1][j] == -1) {
//                    count++;
//                }
//                if (j + 1 < n && (board[i+1][j+1] == 1 || board[i+1][j+1] == -1)) {
//                    count++;
//                }
//            }
//            if (j > 0 && (board[i][j-1] == 1 || board[i][j-1] == -1)) {
//                // left side one
//                count++;
//            }
//            if (j + 1 < n && (board[i][j+1] == 1 || board[i][j+1] == -1)) {
//                // right siede one
//                count++;
//            }
//            if (board[i][j]) {
//                if (count < 2 || count > 3) {
//                    board[i][j] = -1; // to be set to 0
//                }
//            }
//            else {
//                if (count == 3) {
//                    board[i][j] = -2; // to be set to 1
//                }
//            }
//        }
//    }
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (board[i][j] == -1) {
//                board[i][j] = 0;
//            }
//            else if (board[i][j] == -2) {
//                board[i][j] = 1;
//            }
//        }
//    }
//}

// I rewrite the previous version, cut lots of if clauses.
void gameOfLife(vector<vector<int>>& board) {
    int m = (int)board.size(), n = (int)board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int I = max(i-1, 0); I < min(i+2, m); ++I) {
                for (int J = max(j-1, 0); J < min(j+2, n); ++J) {
                    if (I == i && J == j) {
                        continue;
                    }
                    count += board[I][J] & 1;
                }
            }
            if (board[i][j]) {
                if (count < 2 || count > 3) {
                    board[i][j] = -1;
                }
            }
            else if (count == 3) {
                board[i][j] = -2;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
            }
            else if (board[i][j] == -2) {
                board[i][j] = 1;
            }
        }
    }
}


// From BBS
//void gameOfLife(vector<vector<int>>& board) {
//    int m = (int)board.size(), n = m ? (int)board[0].size() : 0;
//    for (int i=0; i<m; ++i) {
//        for (int j=0; j<n; ++j) {
//            int count = 0;
//            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
//                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
//                    count += board[I][J] & 1;
//            if (count == 3 || count - board[i][j] == 3)
//                board[i][j] |= 2;
//        }
//    }
//    for (int i=0; i<m; ++i)
//        for (int j=0; j<n; ++j)
//            board[i][j] >>= 1;
//}

int main(int argc, const char * argv[]) {
    /*
     [0,1,0],
     [0,0,1],
     [1,1,1],
     [0,0,0]
     to
     [0,0,0],
     [1,0,1],
     [0,1,1],
     [0,1,0]
     */
    vector<vector<int>> board{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
//    vector<vector<int>> board{{0,0}};
    gameOfLife(board);
    for (auto v : board) {
        for (auto x : v) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
