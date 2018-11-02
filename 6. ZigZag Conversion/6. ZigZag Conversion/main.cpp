//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by Jie Lu on 2018/9/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    int dir = 1; // 1 for down, -1 for up
    int cur = 0;
    if (numRows == 1) {
        return s;
    }
    vector<string> rows(min(numRows, (int)s.size()));
    for (auto c : s) {
        rows[cur] += c;
        if (cur == 0 && dir == -1) {
            dir = 1;
        }
        else if (cur == rows.size() - 1 && dir == 1) {
            dir = -1;
        }
        cur += dir;
    }
    string res;
    for (auto str : rows) {
        res += str;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<convert("ABC", 1)<<endl;
    return 0;
}
