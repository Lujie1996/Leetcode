//
//  main.cpp
//  680. Valid Palindrome II
//
//  Created by Jie Lu on 2018/9/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool helper(string& s, int i, int j) {
    while (i < j && s[i] == s[j]) {
        i++;
        j--;
    }
    return i >= j;
}

bool validPalindrome(string s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j && s[i] == s[j]) {
        i++;
        j--;
    }
    if (i >= j) {
        return true;
    }
    else {
        return helper(s, i+1, j) || helper(s, i, j-1);
    }
}

int main(int argc, const char * argv[]) {
    if (validPalindrome("deeee")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
