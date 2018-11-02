//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by Jie Lu on 2018/4/21.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int len = (int)s.length() - 1, l = 0, r = len;
    while (l < r) {
        while (l < r && !isalnum(s[l])) {
            l++;
        }
        while (r > l && !isalnum(s[r])) {
            r--;
        }
        if (toupper(s[l]) == toupper(s[r])) {
            l++;
            r--;
            continue;
        }
        else
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (isPalindrome("`l;`` 1o1 ??;l`")) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
