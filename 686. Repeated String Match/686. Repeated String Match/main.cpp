//
//  main.cpp
//  686. Repeated String Match
//
//  Created by Jie Lu on 2018/9/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int repeatedStringMatch(string A, string B) {
    string s = A;
    int k = 1;
    while (s.size() < B.size()) {
        s += A;
        k++;
    }
    if (s.find(B) != string::npos) {
        cout<<s.find(B)<<endl;
        return k;
    }
    s += A;
    if (s.find(B) != string::npos) {
        return ++k;
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    cout<<repeatedStringMatch("abcd", "cdabcdab")<<endl;
    return 0;
}
