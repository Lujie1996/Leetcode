//
//  main.cpp
//  345. Reverse Vowels of a String
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
    int n = (int)s.size(), i = 0, j = n - 1;
    while (i < j) {
        while (i < j && vowels.find(s[i]) == vowels.end()) {
            i++;
        }
        while (i < j && vowels.find(s[j]) == vowels.end()) {
            j--;
        }
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    cout<<reverseVowels("leetcode")<<endl;
    return 0;
}
