//
//  main.cpp
//  567. Permutation in String
//
//  Created by Jie Lu on 2018/10/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

bool mapEqual(int map1[], int map2[]) {
    for (int i = 0; i < 26; i++) {
        if (map1[i] != map2[i]) {
            return false;
        }
    }
    return true;
}

// O(n*m)
bool checkInclusion(string s1, string s2) {
    int map1[26] = {0}, map2[26] = {0};

    for (int i = 0; i < s1.size(); i++) {
        map1[s1[i]-'a'] += 1;
        map2[s2[i]-'a'] += 1;
    }
    if (mapEqual(map1, map2)) {
        return true;
    }
    for (int i = (int)s1.size(); i < s2.size(); i++) {
        map2[s2[i]-'a'] += 1;
        map2[s2[i-s1.size()]-'a'] -= 1;
        if(mapEqual(map1, map2)) {
            return true;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
//    cout<<checkInclusion("hello","ooolleoooleh")<<endl;
    cout<<checkInclusion("ab","a")<<endl;
    return 0;
}
