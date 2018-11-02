//
//  main.cpp
//  73. Set Matrix Zeroes
//
//  Created by Jie Lu on 2018/4/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void displayMatrix(vector<vector<int>>& matrix) {
    for (int i=0; i<matrix.size(); i++) {
        for(int j=0;j<matrix[i].size();j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void setZeroes(vector<vector<int>>& matrix) {
    int nRow = (int)matrix.size(), nCol = (int)matrix[0].size();
    vector<int> rowFlag(nRow, 0), colFlag(nCol, 0);
    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            if (!matrix[i][j]) {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }
    for (i = 0; i < nRow; i++) {
        if (rowFlag[i]) {
            for (j = 0; j < nCol; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (j = 0; j < nCol; j++) {
        if (colFlag[j]) {
            for (i = 0; i< nRow; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix;
    vector<int> nums;
    for (int i = 1; i <= 16; i++) {
        nums.push_back(i);
        if (nums.size() == 4) {
            matrix.push_back(nums);
            nums.clear();
        }
    }
    matrix[2][2] = 0;
    matrix[3][0] = 0;
    setZeroes(matrix);
    displayMatrix(matrix);
    return 0;
}
