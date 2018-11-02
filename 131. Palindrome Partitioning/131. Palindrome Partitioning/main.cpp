//
//  main.cpp
//  131. Palindrome Partitioning
//
//  Created by Jie Lu on 2018/4/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isPal(string s) {
    if (s.length() == 0) {
        return true;
    }
    int l = 0, r = (int)s.length() - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        }
        else
            return false;
    }
    return true;
}
void getPartition(vector<vector<string>>& res, vector<string>& cur, string s) {
    if (s.length() == 0) {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        string prefix = s.substr(0,i+1);
        if (isPal(prefix)) {
            cur.push_back(prefix);
            getPartition(res, cur, s.substr(i+1, s.length() - i -1));
            cur.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    if (s.length() == 0) {
        return res;
    }
    getPartition(res, cur, s);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<vector<string>> res = partition("aab");
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
