//
//  main.cpp
//  49. Group Anagrams
//
//  Created by Jie Lu on 2018/4/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string getKey(string str) {
    int count[26] = {0};
    int i;
    for (i=0; i<str.size(); i++) {
        count[str[i] - 'a'] += 1;
    }
    string res;
    for (i=0; i<26; i++) {
        if (count[i]) {
            string key = "";
            key += (char)(i + 'a');
            key += (char)(count[i] + '0');
            res += key;
        }
    }
    return res;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<int>> group;
    vector<vector<string>> res;
    int i, index;
    for (i=0; i<strs.size(); i++) {
        group[getKey(strs[i])].push_back(i);
    }
    map<string,vector<int>>::iterator iter;
    for (iter=group.begin(); iter!=group.end(); iter++) {
        vector<string> stringInThisKey;
        for (i=0; i<iter->second.size(); i++) {
            index = iter->second[i];
            stringInThisKey.push_back(strs[index]);
        }
        res.push_back(stringInThisKey);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string>> res = groupAnagrams(strs);
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
