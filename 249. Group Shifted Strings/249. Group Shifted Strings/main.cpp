//
//  main.cpp
//  249. Group Shifted Strings
//
//  Created by Jie Lu on 2018/6/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct word {
    string s;
    word(string str) : s(str) {};

    bool operator == (const word& otherWord) const {
        if (s.size() != otherWord.s.size()) {
            return false;
        }
        string s2 = otherWord.s;
        int bias = s2[0] - s[0], i = 1, biased = 0;
        while (i < s.size()) {
            biased = s[i] + bias;
            if (biased < 'a') {
                biased += 26;
            }
            else if (biased > 'z') {
                biased -= 26;
            }
            if (biased == s2[i]) {
                i++;
            }
            else {
                break;
            }
        }
        if (i == s.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};
struct hash_func
{
    size_t operator() (const word &key) const
    {
        return key.s.size();
    }
};
vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<word, vector<string>, hash_func> groups;
    for (auto s : strings) {
        word thisWord(s);
        groups[thisWord].push_back(s);
    }
    vector<vector<string>> res;
    for (auto strs : groups) {
        res.push_back(strs.second);
    }
    return res;
}

/* Another solution from BBS.
   Instead of encapsuing string by defining word, it's easier to use string directly,
   with only one extra step which is using the return value of function shift(string& s) as key to access unorder_map.
 */
//string shift(string& s) {
//    // This function is used to produce the key of string s.
//    string t;
//    int n = (int)s.length();
//    for (int i = 1; i < n; i++) {
//        int diff = s[i] - s[i - 1];
//        if (diff < 0)
//            diff += 26;
//        t += to_string(diff) + ',';
//    }
//    return t;
//}
//vector<vector<string>> groupStrings(vector<string>& strings) {
//    unordered_map<string, vector<string>> mp;
//    for (string  s : strings)
//        mp[shift(s)].push_back(s);
//    vector<vector<string>> groups;
//    for (auto m : mp) {
//        vector<string> group = m.second;
//        groups.push_back(group);
//    }
//    return groups;
//}

int main(int argc, const char * argv[]) {
    vector<string> strings{"abc", "bcd", "acef", "xyz", "az", "as", "ba", "a", "z"};
//    for (auto s : strings) {
//        cout<<s<<" -> "<<shift(s)<<endl;
//    }
    vector<vector<string>> res = groupStrings(strings);
    for (auto strs : res) {
        for (auto str : strs) {
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}
