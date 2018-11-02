//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> res;
    vector<vector<char>> dict;
    vector<char> letter2{'a','b','c'}, letter3{'d','e','f'}, letter4{'g','h','i'}, letter5{'j','k','l'},
    letter6{'m','n','o'}, letter7{'p','q','r','s'}, letter8{'t','u','v'}, letter9{'w','x','y','z'};
    dict.push_back(letter2);
    dict.push_back(letter3);
    dict.push_back(letter4);
    dict.push_back(letter5);
    dict.push_back(letter6);
    dict.push_back(letter7);
    dict.push_back(letter8);
    dict.push_back(letter9);
    for (char c : digits) {
        int num = c - ('0' - 0);
        vector<string> tmp;
        string t = "";
        for (char candidate : dict[num - 2]) {
            if (res.size() == 0) {
                tmp.push_back(t + candidate);
            }
            else {
                for (string s : res) {
                    tmp.push_back(s + candidate);
                }
            }
        }
        res = tmp;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<to_string('a')<<endl;
    vector<string> res = letterCombinations("23");
    for (auto str : res) {
        cout<<str<<" ";
    }
    cout<<endl;
    return 0;
}
