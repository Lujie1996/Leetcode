//
//  main.cpp
//  304. Range Sum Query 2D - Immutable
//
//  Created by Jie Lu on 2018/6/26.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
    int m, n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        m = (int)matrix.size();
        if (m > 0) {
            n = (int)matrix[0].size();
        }
        sum.resize(m + 1);
        for (auto& row : sum) {
            row.resize(n + 1);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return sum[row2][col2] - sum[row2][col1-1] - sum[row1-1][col2] + sum[row1-1][col1-1];
    }
};
int main(int argc, const char * argv[]) {
    /*
     [3, 0, 1, 4, 2],
     [5, 6, 3, 2, 1],
     [1, 2, 0, 1, 5],
     [4, 1, 0, 1, 7],
     [1, 0, 3, 0, 5]
     */
//    vector<vector<int>> matrix{{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    vector<vector<int>> matrix{{4,5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout<<obj->sumRegion(0,0,0,1)<<endl;
    return 0;
}
