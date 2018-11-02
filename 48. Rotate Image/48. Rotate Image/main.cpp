//
//  main.cpp
//  48. Rotate Image
//
//  Created by Jie Lu on 2018/4/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = (int)matrix[0].size();
    int row, col, nextRow, nextCol, old, pre, count=0;
    while(n > 1) {
        for (int i=0; i<n-1; i++) {
            row =  0;
            col =  i;
            pre = matrix[count + row][count + col];
            for (int j=0; j<4; j++) {
                nextRow = col;
                nextCol = n - row - 1;
                old = matrix[count + nextRow][count + nextCol];
                matrix[count + nextRow][count + nextCol] = pre;
                cout<<count+nextRow<<" "<<count+nextCol<<endl;
                pre = old;
                row = nextRow;
                col = nextCol;
            }
        }
        n-=2;
        count++;
    }
}
void displayMatrix(vector<vector<int>>& matrix) {
    for (int i=0; i<matrix.size(); i++) {
        for(int j=0;j<matrix[i].size();j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
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
    rotate(matrix);
    displayMatrix(matrix);
    return 0;
}
