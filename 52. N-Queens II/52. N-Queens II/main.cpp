//
//  main.cpp
//  52. N-Queens II
//
//  Created by Jie Lu on 2018/9/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void helper(vector<int>& cur, int row, int n, int& count) {
    if (row == n) {
        count += 1;
        return;
    }
    for (int col = 0; col < n; col++) {
        bool isValid = true;
        for (int i = 0; i < cur.size(); i++) {
            if (col == cur[i] || abs(i - row) == abs(cur[i] - col)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            cur.push_back(col);
            helper(cur, row+1, n, count);
            cur.pop_back();
        }
    }
}

int totalNQueens(int n) {
    vector<int> cur;
    int count = 0;
    helper(cur, 0, n, count);
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
