//
//  main.cpp
//  459. Repeated Substring Pattern
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int len = (int)s.size();
    for (int patternLen = 1; patternLen <= len / 2; patternLen++) {
        // try different pattern the len of which is increasing from 1 to len/2
        if (len % patternLen != 0) {
            continue;
            // patternLen必须被能len整除
        }
        int i = patternLen;
        while (i < len) {
            if (s[i] == s[i % patternLen]) {
                i++;
                continue;
            }
            else {
                break;
            }
        }
        if (i == len) {
            return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    if (repeatedSubstringPattern("abaababaab")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
