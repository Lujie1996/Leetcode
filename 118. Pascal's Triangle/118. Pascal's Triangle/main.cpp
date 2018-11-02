//
//  main.cpp
//  118. Pascal's Triangle
//
//  Created by Jie Lu on 2018/4/21.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows == 0) {
        return res;
    }
    res.push_back(vector<int>(1,1));
    vector<int>row;
    for (int i = 2; i <= numRows; i++) {
        row.push_back(1);
        for (int j = 0; j < i - 2; j++) {
            int prevRow = i - 2;
            row.push_back(res[prevRow][j] + res[prevRow][j+1]);
        }
        row.push_back(1);
        res.push_back(row);
        row.clear();
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int numRows;
    cin>>numRows;
    vector<vector<int>> res = generate(numRows);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
