//
//  main.cpp
//  434. Number of Segments in a String
//
//  Created by Jie Lu on 2018/5/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int countSegments(string s) {
    int n = (int)s.size(), count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) {
            count++;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    cout<<countSegments("a")<<endl;
    cout<<countSegments("Hello, my name is John")<<endl;
    return 0;
}
