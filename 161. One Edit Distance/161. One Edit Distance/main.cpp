//
//  main.cpp
//  161. One Edit Distance
//
//  Created by Jie Lu on 2018/8/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool canAddOneDigit(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && s[i] == t[j]) {
        i++;
        j++;
    }
    j++;
    while (i < s.size() && s[i] == t[j]) {
        i++;
        j++;
    }
    return i == s.size();
}
bool isOneEditDistance(string s, string t) {
    if (s.size() + 1 == t.size()) {
        return canAddOneDigit(s, t);
    }
    if (t.size() + 1 == s.size()) {
        return canAddOneDigit(t, s);
    }
    if (s.size() == t.size()) {
        int i = 0;
        while (i < s.size() && s[i] == t[i]) {
            i++;
        }
        i++;
        while (i < s.size() && s[i] == t[i]) {
            i++;
        }
        return i == s.size();
    }
    return false;
}
int main(int argc, const char * argv[]) {
    if (isOneEditDistance("1234", "1344")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
