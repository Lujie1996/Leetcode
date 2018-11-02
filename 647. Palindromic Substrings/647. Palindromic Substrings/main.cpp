//
//  main.cpp
//  647. Palindromic Substrings
//
//  Created by Jie Lu on 2018/5/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int countSubstrings(const string& s) {
    int n = (int)s.size(), count = 0, i, j;
    for (i = 0; i < n; i++) {
        // i is the center of parlindrome
        // j is the length of palindrome
        for (j = 0; i - j >= 0 && i + j < n; j++) {
            if (s[i - j] == s[i + j]) {
                count++;
            }
            else {
                break;
            }
        }
        for (j = 1; i - j >= 0 && i + j - 1 < n; j++) {
            if (s[i -j] == s[i + j - 1]) {
                count++;
            }
            else {
                break;
            }
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    cout<<countSubstrings("aaaaa")<<endl;
    return 0;
}
