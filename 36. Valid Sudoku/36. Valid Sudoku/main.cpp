//
//  main.cpp
//  36. Valid Sudoku
//
//  Created by Jie Lu on 2018/4/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int flag1[9][9] = {0}, flag2[9][9] = {0}, flag3[9][9] = {0};
    // flag1[i][j] tracks if number j on ith row has shwon up
    // flag2[i][j] tracks if number j on ith column has shown up
    // flag3[i][j] tracks if number j on ith 3x3-Square has shown up
    int k, num;
    for(int i=0;i<9;i++){
        for (int j=0;j<9; j++) {
            if(board[i][j] != '.') {
                num = board[i][j] - '0' - 1;
                k = i / 3 * 3 + j / 3;
                if(flag1[i][num] || flag2[j][num] || flag3[k][num])
                    return false;
                flag1[i][num] = flag2[j][num] = flag3[k][num] = 1;
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
