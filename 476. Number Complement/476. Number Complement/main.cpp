//
//  main.cpp
//  476. Number Complement
//
//  Created by Jie Lu on 2018/7/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 idea:
 e.g. num = 5 = ... 0000 0101
 flip every bit except sign bit: 11111010
 it has to decrement the leading 1s, which is base
 use a loop t0 find the highest 1 in number and record the base
 */
int findComplement(int num) {
    int i = 0, mask = 1 << 30, base = 0;
    while (((num << i) & mask) == 0) {
        base += (1 << (30 - i));
        i++;
    }
    return ~num + 2 * mask - base;
    // ~num + 2 * mask is to flip all bits except the MSB (sign bit)
}
int main(int argc, const char * argv[]) {
    cout<<findComplement(5)<<endl;
    return 0;
}
