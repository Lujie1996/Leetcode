//
//  main.cpp
//  844. Backspace String Compare
//
//  Created by Jie Lu on 2018/9/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int compress(string& s) {
    int i = 0, j = 0;
    while (j < s.size()) {
        if (s[j] == '#') {
            if (i > 0) {
                i--;
            }
        }
        else {
            s[i] = s[j];
            i++;
        }
        j++;
    }
    return i;
}

bool backspaceCompare(string S, string T) {
    int lenS = compress(S);
    int lenT = compress(T);
    if (lenS != lenT) {
        return false;
    }
    
    int i = 0;
    for (; i < lenS; i++) {
        if (S[i] != T[i]) {
            break;
        }
    }
    return i == lenS;
}
int main(int argc, const char * argv[]) {
    cout<<backspaceCompare("a##c", "#a#c")<<endl;
    return 0;
}
