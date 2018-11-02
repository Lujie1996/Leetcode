//
//  main.cpp
//  266. Palindrome Permutation
//
//  Created by Jie Lu on 2018/6/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool canPermutePalindrome(string s) {
    int count[256] = {0};
    for (auto c : s) {
        count[c] += 1;
    }
    int odd = 0;
    for (auto a : count) {
        if (a % 2 != 0) {
            odd++;
        }
    }
    return odd <= 1;
}
int main(int argc, const char * argv[]) {
    if (canPermutePalindrome("aaab")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
