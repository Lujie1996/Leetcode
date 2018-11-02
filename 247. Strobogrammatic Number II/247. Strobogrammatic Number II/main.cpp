//
//  main.cpp
//  247. Strobogrammatic Number II
//
//  Created by Jie Lu on 2018/6/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> findStrobogrammatic(int n) {
    vector<string> res;
    string str(n, 0);
    res.push_back(str);
    vector<char> cand{'1','6','8','9'};
    // The first number cannot be '0'
    for (int i = 0; i < (n + 1) / 2; i++) {
        // i traverse from the left-most position to the center of string.
        vector<string> tmpRes;
        if (i == 1) {
            vector<char> newCand{'0','1','6','8','9'};
            // After obtaining the first number, candidate number should include '0'
            cand = newCand;
        }
        if (n % 2 == 1 && i == (n + 1) / 2 - 1) {
            vector<char> newCand{'0','1','8'};
            // When length is a odd number and i comes to the center of string
            cand = newCand;
        }
        for (auto s : res) {
            for (auto c : cand) {
                string tmp = s;
                tmp[i] = c;
                if (c == '6') {
                    tmp[n-i-1] = '9';
                }
                else if (c == '9') {
                    tmp[n-i-1] = '6';
                }
                else {
                    tmp[n-i-1] = c;
                }
                tmpRes.push_back(tmp);
            }
        }
        res = tmpRes;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = findStrobogrammatic(1);
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
