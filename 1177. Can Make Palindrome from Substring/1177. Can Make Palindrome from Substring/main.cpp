//
//  main.cpp
//  1177. Can Make Palindrome from Substring
//
//  Created by Jie Lu on 2019/9/6.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool canMake(vector<vector<int>>& charCount, vector<int>& query) {
    vector<int> count(26, 0);
    for (int i = 0; i < 26; i++) {
        count[i] = charCount[query[1]+1][i] - charCount[query[0]][i];
    }
    int oddCount = 0;
    for (auto num : count) {
        oddCount += num % 2;
    }

    return oddCount / 2 <= query[2];
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<vector<int>> charCount;
    vector<int> count(26, 0);
    
    charCount.push_back(count);
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a'] += 1;
        charCount.push_back(count);
    }
    
    vector<bool> res;
    for (auto query : queries) {
        res.push_back(canMake(charCount, query));
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> queries{{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
    auto res = canMakePaliQueries("abcda", queries);
    for (auto a : res) {
        cout<<a<<endl;
    }
    return 0;
}
