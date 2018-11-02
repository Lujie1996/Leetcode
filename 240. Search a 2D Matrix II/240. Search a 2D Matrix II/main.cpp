//
//  main.cpp
//  240. Search a 2D Matrix II
//
//  Created by Jie Lu on 2018/5/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// the upper-right element is the special one: all elements less than it are at its left side and all elements greater than it are behind.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = (int)matrix.size();
    if (m == 0)
        return false;
    int n = (int)matrix[0].size(), r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
