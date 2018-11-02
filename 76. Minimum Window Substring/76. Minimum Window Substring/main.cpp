//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 i.e.:
 s : M Q A D B P C N X W A B Y C D         t : A B C
         i       j
 sMap[c]: map recording how many character c appears in substring s[i..j];
 tMap[c]: map recording how many character c appears in string t;
 
 When j points to C, by sMap[s[j]] < tMap[s[j]] && count == t.length (count += 1 after add this char),
 we have a window which takes j as right bound and it contains all chars in t.
 How to get a shorter window?
 We shift rightwards the pointer i while making ensure sMap[s[i]] >= tMap[s[i]] (to ensure the window is able to cover string t).
 */
string minWindow(string s, string t) {
    int sMap[128] = {0}, tMap[128] = {0};
    int count = 0, minWinLen = (int)s.size(), startPos = 0, i = 0, j = 0;
    bool isComplete = false;
    for (char c : t) {
        tMap[c] += 1;
    }
    for (j = 0; j < s.length(); j++) {
        char c = s[j];
        if (tMap[c] == 0) {
            continue;
        }
        if (sMap[c] < tMap[c]) {
            count++;
            // count is only increased when sMap[c] < tMap[c], otherwise we can't use count == t.length() to tell the window is complete
            if (count == t.length()) {
                isComplete = true;
            }
        }
        sMap[c] += 1;
        while (i < j) {
            if (tMap[s[i]] == 0) {
                i++;
            }
            else if (sMap[s[i]] > tMap[s[i]]) {
                sMap[s[i]] -= 1;
                i++;
            }
            else {
                // pointer i can no longer shift, otherwise the window will be incomplete
                break;
            }
        }
        if (isComplete && j - i + 1 < minWinLen) {
            minWinLen = j - i + 1;
            startPos = i;
        }
    }
    return isComplete ? s.substr(startPos, minWinLen) : "";
}
int main(int argc, const char * argv[]) {
    cout<<minWindow("a", "aa")<<endl;
    return 0;
}
