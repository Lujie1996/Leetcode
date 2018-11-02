//
//  main.cpp
//  520. Detect Capital
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

/*
 Given a word, you need to judge whether the usage of capitals in it is right or not.
 
 We define the usage of capitals in a word to be right when one of the following cases holds:
 
 All letters in this word are capitals, like "USA".
 All letters in this word are not capitals, like "leetcode".
 Only the first letter in this word is capital if it has more than one letter, like "Google".
 Otherwise, we define that this word doesn't use capitals in a right way.
 */

#include <iostream>
using namespace std;

bool detectCapitalUse(string word) {
    int n = (int)word.length();
    if (n == 1) {
        return true;
    }
    if (word[0] < 'a') { // first letter is Uppercase
        if (word[1] < 'a') { // second letter is Uppercase
            for (int i = 2; i < n; i++) {
                if (word[i] >= 'a') { // should be all Uppercase
                    return false;
                }
            }
        }
        else {
            for (int i = 2; i < n; i++) { // should be all Lowercase
                if (word[i] < 'a') {
                    return false;
                }
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) { // should be all Lowercase
            if (word[i] < 'a') {
                return false;
            }
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (detectCapitalUse("USA")) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
