//
//  main.cpp
//  216. Combination Sum III
//
//  Created by Jie Lu on 2018/4/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getCombination(vector<vector<int>>& res, vector<int>& cur, int k, int n, int start) {
    if (k == 0 && n == 0) {
        res.push_back(cur);
        return;
    }
    if (n < 0) {
        return;
    }
    for (int i = start; i <= 9; i++) {
        cur.push_back(i);
        getCombination(res, cur, k - 1, n - i, i + 1);
        cur.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    getCombination(res, cur, k, n, 1);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> res = combinationSum3(3, 9);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
