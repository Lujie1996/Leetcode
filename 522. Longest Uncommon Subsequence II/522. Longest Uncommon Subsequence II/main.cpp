//
//  main.cpp
//  522. Longest Uncommon Subsequence II
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool hasSubsequence(const string& s1, const string& s2) {
    // return true if s2 is a subsequence of s1
    if (s1.size() == s2.size()) {
        if (s1 == s2) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        int i = 0, j = 0;
        while (j < s2.size()) {
            char target = s2[j];
            while (i < s1.size() && s1[i] != target) {
                i++;
            }
            if (i == s1.size()) {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
}
int findLUSlength(vector<string>& strs) {
    sort(strs.begin(), strs.end(), [](const string& a, const string& b){return a.size() > b.size();});
    // sort strs in length-descending order
    int len = -1;
    bool hasCS = false;
    for (int i = 0; i < strs.size(); i++) {
        // the strs is already in length-descending order
        // if current str (length = len) is not a subsequence of any str whose length >= len, then return len
        len = (int)strs[i].size();
        int j = 0;
        hasCS = false;
        for (; j < strs.size() && strs[j].size() >= len; j++) {
            if (i == j) {
                continue;
            }
            if (hasSubsequence(strs[j], strs[i])) {
                // find one str which contains a subsequence strs[i], thus strs[i] is not eligible for LUS.
                // Try next strs[i]
                hasCS = true;
                break;
            }
        }
        if (hasCS == false) {
            // any str whose length >= len doesn't have a subsequence strs[i], thus strs[i] can be the LUS
            break;
        }
    }
    //the above for loop can be terminated by either has == false or i == strs.size(). The latter case means there is no LUS.
    return hasCS == true ? -1 : len;
}
int main(int argc, const char * argv[]) {
    vector<string> strs{"abcabc","abcabc","abcabc","abc","abc","cca"};
    cout<<findLUSlength(strs)<<endl;
    return 0;
}
