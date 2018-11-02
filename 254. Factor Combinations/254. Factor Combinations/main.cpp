//
//  main.cpp
//  254. Factor Combinations
//
//  Created by Jie Lu on 2018/6/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void getOneFactor(vector<vector<int>>& res, vector<int>& cur, int n, int start) {
    if (n == 1) {
        if (res.size() == 0) {
            return; // to avoid res = [[]] when initial input n == 1
        }
        res.push_back(cur);
        return;
    }
    if (cur.size() > 0 && n >= 2) {
        cur.push_back(n);
        res.push_back(cur);
        cur.pop_back();
    }
    for (int i = start; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cur.push_back(i);
            getOneFactor(res, cur, n / i, i);
            cur.pop_back();
        }
    }
}
vector<vector<int>> getFactors(int n) {
    vector<vector<int>> res;
    vector<int> cur;
    getOneFactor(res, cur, n, 2);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> res = getFactors(32);
    for (auto vec : res) {
        for (auto a : vec) {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
