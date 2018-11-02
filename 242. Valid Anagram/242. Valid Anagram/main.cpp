//
//  main.cpp
//  242. Valid Anagram
//
//  Created by Jie Lu on 2018/5/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> countLetters;
    for (auto c : s) {
        countLetters[c] += 1; // STL map: if key does not exist, create pair and use default construct function.
    }
    for (auto c : t) {
        countLetters[c] -= 1;
    }
    for (auto p : countLetters) {
        if (p.second != 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (isAnagram("rat", "tar")) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
