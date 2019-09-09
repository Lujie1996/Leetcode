//
//  main.cpp
//  1165. Single-Row Keyboard
//
//  Created by Jie Lu on 2019/8/27.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int calculateTime(string keyboard, string word) {
    if (word.size() == 0) {
        return 0;
    }
    int charIndex[26] = {0};
    for (int i = 0; i < 26; i++) {
        charIndex[keyboard[i]-'a'] = i;
    }
    int sum = 0;
    int preIndex = 0;
    for (char c : word) {
        sum += abs(charIndex[c-'a'] - preIndex);
        preIndex = charIndex[c-'a'];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cout<<calculateTime("abcdefghijklmnopqrstuvwxyz", "cba")<<endl;
    return 0;
}
