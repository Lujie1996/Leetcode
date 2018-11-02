//
//  main.cpp
//  387. First Unique Character in a String
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int firstUniqChar(string s) {
    int hash[26] = {0};
    for (auto c : s) {
        hash[c - 'a'] += 1;
    }
    for (int i = 0; i < (int)s.size(); i++) {
        if (hash[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cout<<firstUniqChar("loveleetcode")<<endl;
    return 0;
}
