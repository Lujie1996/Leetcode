//
//  main.cpp
//  383. Ransom Note
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool canConstruct(const string& ransomNote, const string& magazine) {
    int map[26] = {0};
    for (char c : magazine) {
        map[c - 'a'] += 1;
    }
    for (char c : ransomNote) {
        if (--map[c - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (canConstruct("aaa", "sdfsfasdsa")) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"no"<<endl;
    }
    return 0;
}
