//
//  main.cpp
//  293. Flip Game
//
//  Created by Jie Lu on 2018/6/26.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    int i = 0, n = (int)s.size();
    while (i < n) {
        if (s[i] == '+') {
            if (i + 1 < n && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                res.push_back(s);
                s[i] = '+';
                s[i+1] = '+';
            }
            else {
                i++;
            }
        }
        i++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = generatePossibleNextMoves("++++");
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
