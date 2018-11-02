//
//  main.cpp
//  524. Longest Word in Dictionary through Deleting
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isValid(string& s1, string& s2) {
    int j = 0;
    for (int i = 0; i < s1.size() && j <s2.size(); i++) {
        if (s1[i] == s2[j]) {
            j++;
        }
    }
    
    return j == s2.size();
}

string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end());
    
    int maxLen = 0;
    string res;
    for (auto ss : d) {
        if (isValid(s, ss)) {
            if (ss.size() > maxLen) {
                maxLen = ss.size();
                res = ss;
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<findLongestWord(s, d)<<endl;
    return 0;
}
