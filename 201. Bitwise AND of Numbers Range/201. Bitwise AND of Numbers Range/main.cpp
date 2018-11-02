//
//  main.cpp
//  201. Bitwise AND of Numbers Range
//
//  Created by Jie Lu on 2018/4/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Consider the highest digit in m and n, only when m and n are both greater than base, will the digit in result be 1.
// E.g., m = 5 (0x101), n = 7(0x111), 5 and 7 are greater than base 0x100 which is 4, then this digit in result will be 1.
// m and n both reduce by 4, that is m = 1(0x01) and n = 3(0x11), and the base comes to 2. Not greater, so this digit in result is 0.
// Also, reduce them by 2 but ensure they are greater than 1, that is m = 0(0x0) and n = 1(0x1).

int rangeBitwiseAnd(int m, int n) {
    int res = 0, base = 0x1 << 30;
    for (int i = 30; i >= 0; i--) {
        if (m >= base && n >= base) {
            res |= (0x1 << i);
            m -= base;
            n -= base;
        }
        else if (m >= base && n < base) {
            m -= base;
            n = 0;
        }
        else if (m < base && n >= base) {
            m = 0;
            n -= base;
        }
        base /= 2;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<rangeBitwiseAnd(5, 7)<<endl;
    return 0;
}
