//
//  main.cpp
//  205. Isomorphic Strings
//
//  Created by Jie Lu on 2018/4/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t) {
    // keep corresponding chars map to one number
    int m1[256] = {0}, m2[256] = {0}, n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (isIsomorphic("ab", "aa")) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
