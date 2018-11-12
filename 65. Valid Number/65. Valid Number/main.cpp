//
//  main.cpp
//  65. Valid Number
//
//  Created by Jie Lu on 2018/11/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <regex>
using namespace std;

bool isNumber(string s) {
    regex const pattern{R"(^\s*[-+]?(?:\d+|\d+\.\d*|\d*\.\d+)(?:e[+-]?\d+)?\s*$)"};
    return regex_match(s, pattern);
}

// DFA (Deterministic Finite Automaton)
// https://leetcode.com/problems/valid-number/discuss/23725/C++-My-thought-with-DFA
bool isNumber2(string str) {
    int state = 0, flag = 0; // flag to judge the special case "."
    
    while (str[0]==' ')
        str.erase(0,1); //delete the prefix whitespace
    while (str[str.length()-1] == ' ')
        str.erase(str.length()-1, 1); //delete the suffix whitespace
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            flag = 1;
            if (state <= 2)
                state = 2;
            else
                state = (state <= 5) ? 5 : 7;
        }
        else if ('+' == str[i] || '-' == str[i]) {
            if (state == 0 || state == 3)
                state++;
            else
                return false;
        }
        else if( '.' == str[i]) {
            if (state <= 2)
                state = 6;
            else
                return false;
        }
        else if ('e' == str[i]) {
            if (flag && (state == 2 || state == 6 || state == 7))
                state = 3;
            else
                return false;
        }
        else
            return false;
    }
    return state == 2 || state == 5 || (flag && state == 6) || state == 7;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}



class Solution {
private:
    static std::regex const number_pattern;
public:
    bool isNumber(std::string const& s) {
        return std::regex_match(s, number_pattern);
    }
};
