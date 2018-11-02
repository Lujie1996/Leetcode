//
//  main.cpp
//  187. Repeated DNA Sequences
//
//  Created by Jie Lu on 2018/4/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> seen, repeated;
    for (int i = 0; i + 9 < s.length(); i++) {
        string ten = s.substr(i, 10);
        if (!seen.insert(ten).second) {
            repeated.insert(ten);
        }
    }
    return vector<string>(repeated.begin(), repeated.end());
}
int main(int argc, const char * argv[]) {
    vector<string> res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (string s : res) {
        cout<<s<<endl;
    }
    return 0;
}
