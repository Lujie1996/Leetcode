//
//  main.cpp
//  541. Reverse String II
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string reverseStr(string s, int k) {
    int low = 0, high = 0, n = (int)s.length(), lowStart = 0;
    char c;
    while (low < n) {
        high = low + k - 1 < n ? low + k - 1 : n - 1;
        while (low < high) {
            c = s[low];
            s[low] = s[high];
            s[high] = c;
            low++;
            high--;
        }
        lowStart += 2 * k;
        low = lowStart;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    cout<<reverseStr("abcdefg", 1212)<<endl;
    return 0;
}
