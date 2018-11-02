//
//  main.cpp
//  482. License Key Formatting
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string licenseKeyFormatting(string S, int K) {
    string res;
    int i = (int)S.size() - 1;
    while (i >= 0) {
        int count = 0;
        string part;
        while (i >= 0 && count < K) {
            if (S[i] != '-') {
                S[i] = toupper(S[i]);
                part = S[i] + part;
                count++;
            }
            i--;
        }
        res = part + ((part == "" || res == "" ) ? "" : "-") + res;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<licenseKeyFormatting("5F3Z-2e-9-w", 4)<<endl;
    return 0;
}
