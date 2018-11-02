//
//  main.cpp
//  766. Toeplitz Matrix
//
//  Created by Jie Lu on 2018/10/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool checkDiagonal(int i, int j, vector<vector<int>>& matrix) {
    int target = matrix[i][j];
    while (i < matrix.size() && j < matrix[0].size()) {
        if (matrix[i][j] != target) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return true;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (!checkDiagonal(i, 0, matrix)) {
            return false;
        }
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        if (!checkDiagonal(0, i, matrix)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    /*
     matrix = [
     [1,2,3,4],
     [5,1,2,3],
     [9,5,1,2]
     ]
     */
    vector<vector<int>> matrix{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    cout<<isToeplitzMatrix(matrix)<<endl;
    return 0;
}
