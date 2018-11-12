//
//  main.cpp
//  791. Custom Sort String
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string customSortString(string S, string T) {
    vector<int> count(26, 0);
    for (auto c : T) {
        count[c-'a'] += 1;
    }
    
    string res;
    for (char c : S) {
        for (int i = 0; i < count[c-'a']; i++) {
            res += c;
        }
        count[c-'a'] = 0;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            char c = 'a' + i;
            for (int j = 0; j < count[i]; j++) {
                res += c;
            }
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
