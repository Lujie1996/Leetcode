//
//  main.cpp
//  171. Excel Sheet Column Number
//
//  Created by Jie Lu on 2018/4/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string s) {
    int res = 0, base = 1;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        res += (s[i] - 'A' + 1) * base;
        base *= 26;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    string str;
    while (cin>>str) {
        cout<<titleToNumber(str)<<endl;
    }
    return 0;
}
