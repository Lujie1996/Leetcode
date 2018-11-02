//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by Jie Lu on 16/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// Enumeration around center. O(n^2) time O(1) space
//string longestPalindrome(string s) {
//    int n = (int)s.size(), maxLen = 0, maxLenStart = 0, i = 0, j = 0;
//    for (i = 0; i < n; i++) {
//        for (j = 0; i - j >= 0 && i + j < n; j++) {
//            if (s[i-j] != s[i+j]) {
//                break;
//            }
//        }
//        j--;
//        if (2 * j + 1 > maxLen) {
//            maxLenStart = i - j;
//            maxLen = 2 * j + 1;
//        }
//    }
//
//    for (i = 1; i < n; i++) {
//        for (j = 1; i - j >= 0 && i + j - 1 < n; j++) {
//            if (s[i-j] != s[i+j-1]) {
//                break;
//            }
//        }
//        j--;
//        if (2 * j > maxLen) {
//            maxLenStart = i - j;
//            maxLen = 2 * j;
//        }
//    }
//    return s.substr(maxLenStart, maxLen);
//}

// DP solution. O(n^2) time and space
// Idea is similar to LC 516. Longest Palindromic Subsequence
//string longestPalindrome(string s) {
//    int n = (int)s.size(), longest = 0, start = 0;
//    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
//    for (int i = 0; i < n; i++) {
//        isPalindrome[i][i] = true;
//        longest = 1;
//        start = i;
//    }
//    for (int i = 0; i < n - 1; i++) {
//        isPalindrome[i][i+1] = s[i] == s[i+1];
//        if (isPalindrome[i][i+1]) {
//            longest = 2;
//            start = i;
//        }
//    }
//    for (int i = n - 2; i >= 0; i--) {
//        for (int j = i + 2; j < n; j++) {
//            isPalindrome[i][j] = (isPalindrome[i+1][j-1] && s[i] == s[j]);
//            if (isPalindrome[i][j] && j - i + 1 > longest) {
//                longest = j - i + 1;
//                start = i;
//            }
//        }
//    }
//    return s.substr(start, longest);
//}

// Another more concise DP implementation
string longestPalindrome(string s) {
    int n = (int)s.size(), longest = 0, start = 0;
    if (n < 2) {
        return s;
    }
    vector<vector<bool>> isPalindrome(n, vector<bool>(n));
    // isPalindrome[i][j] 表示s[i...j]是否是回文串
    for (int i = 0; i < n; i++){  // i作为终点
        int j = i;    // j作为起点
        while (j >= 0){
            if (s[i] == s[j] && (i - j < 2 || isPalindrome[j+1][i-1])){
                isPalindrome[j][i] = true;
                if (i - j + 1 > longest) {
                    start = j;
                    longest = i - j + 1;
                }
            }
            j--;
        }
    }
    return s.substr(start, longest);
}

// There is actually a faster solution using Manacher's Algorithm. O(n) time

int main(int argc, const char * argv[]) {
    string s="abcdzdcab";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
