//
//  main.cpp
//  419. Battleships in a Board
//
//  Created by Jie Lu on 2018/6/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// My idea. One-pass, O(1) space, very elegant :)
int countBattleships(vector<vector<char>>& board) {
    if (board.size() == 0) {
        return 0;
    }
    int m = (int)board.size(), n = (int)board[0].size(), count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            else {
                if (i > 0 && board[i-1][j] == 'X') {
                    continue; // already counted
                }
                if (j == n - 1 || board[i][j+1] == '.') {
                    count++;
                }
            }
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    /*
     X X . . X
     . . X . X
     X . X . .
     */
    vector<vector<char>> board1{{'X','X','.','.','X'},{'.','.','X','.','X'},{'X','.','X','.','.'}};
    vector<vector<char>> board2{{'X'},{'.'}};
    cout<<countBattleships(board1)<<endl;
    cout<<countBattleships(board2)<<endl;
    return 0;
}
