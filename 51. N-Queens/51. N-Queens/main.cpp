//
//  main.cpp
//  51. N-Queens
//
//  Created by Jie Lu on 2018/9/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> toString(vector<int>& points) {
    vector<string> res;
    int n = (int)points.size();
    for (auto col : points) {
        string thisRow;
        for (int i = 0; i < n; i++) {
            if (i == col) {
                thisRow += 'Q';
                continue;
            }
            thisRow += ".";
        }
        res.push_back(thisRow);
    }
    return res;
}

void helper(vector<vector<string>>& res, vector<int>& cur, int row, int n) {
    if (row == n) {
        res.push_back(toString(cur));
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
            helper(res, cur, row+1, n);
            cur.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int> cur;
    helper(res, cur, 0, n);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> res = solveNQueens(4);
    for (auto a : res) {
        for (auto s : a) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
