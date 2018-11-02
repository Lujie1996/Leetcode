//
//  main.cpp
//  214. Shortest Palindrome
//
//  Created by Jie Lu on 2018/9/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool isValid(string& s, int i, int j) {
    while (i < j && s[i] == s[j]) {
        i++;
        j--;
    }
    return i >= j;
}

string shortestPalindrome(string s) {
    if (s.size() == 0 || isValid(s, 0, (int)s.size() - 1)) {
        return s;
    }
    
    string res;
    
    int mid = ((int)s.size()  - 1)/ 2;
    while (mid >= 0) {
        // add length palindrome
        if (isValid(s, 0, 2*mid)) {
            string additional = s.substr(2*mid+1);
            reverse(additional.begin(), additional.end());
            res = additional + s;
            break;
        }
        mid--;
        if (isValid(s, 0, 2*(mid+1)-1)) {
            string additional = s.substr(2*(mid+1));
            reverse(additional.begin(), additional.end());
            res = additional + s;
            break;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<shortestPalindrome("aacecaaa")<<endl;
    return 0;
}
