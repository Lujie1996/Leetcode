//
//  main.cpp
//  678. Valid Parenthesis String
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

// solution from discuss
/*
 Since * can be used as 3 kinds of char, if we do backtrack the complexity can blow up if the string is *****.... We need to find a non-trivial method.
 Without *, we can just use a number to indicate the unmatch (, ( will increment it and ) will decrement it. We don't want this number less than 0 all the time and it should be 0 when all the string has been matched.
 When * is introduced, the number becomes a range, indicating the number of possible unmatched ( found. One * just expand the range by 1. And we can use the same principle to check if the criteria above is within the range.
 

 */
bool checkValidString(string s) {
    int lower = 0, upper = 0;
    for (char c : s) {
        if (c == '(') {
            lower++;
            upper++;
        }
        else if (c == ')') {
            lower--;
            upper--;
        }
        else { // * encountered
            lower--;
            upper++;
        }
        lower = max(lower, 0);
        if (upper < 0)
            // unmatched ')' found in the middle of string
            return false;
    }
    return lower == 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
