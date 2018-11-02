//
//  main.cpp
//  389. Find the Difference
//
//  Created by Jie Lu on 2018/6/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

char findTheDifference(const string& s, const string& t) {
    int hash[26] = {0};
    char res = 0;
    for (char c : s)
        hash[c - 'a'] += 1;
    for (char c : t)
        hash[c - 'a'] -= 1;
    for (int i = 0; i < 26; i++) {
        if (hash[i] == -1) {
            res = i + 'a';
        }
    }
    return res;
}
// Very smart idea using the one for problem Single Number:
//char findTheDifference(string s, string t) {
//    char r=0;
//    for(char c:s) r ^=c;
//    for(char c:t) r ^=c;
//    return r;
//}
int main(int argc, const char * argv[]) {
    cout<<findTheDifference("abcd", "abscd")<<endl;
    return 0;
}
