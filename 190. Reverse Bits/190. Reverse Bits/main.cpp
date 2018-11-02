//
//  main.cpp
//  190. Reverse Bits
//
//  Created by Jie Lu on 2018/4/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;
uint32_t reverseBits(uint32_t n) {
    unsigned mask = 1, i = 1, res = 0;
    while (i <= 32) {
        cout<<res<<endl;
        if (mask & n) {
            res |= (1<<(32-i));
        }
        i++;
        mask *= 2;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<reverseBits(43261596)<<endl;
    return 0;
}
