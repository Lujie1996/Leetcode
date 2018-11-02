//
//  main.cpp
//  172. Factorial Trailing Zeroes
//
//  Created by Jie Lu on 2018/4/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int res = 0;
    while (n) {
        res += n / 5;
        n /= 5;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin>>n) {
        cout<<trailingZeroes(n)<<endl;
    }
    return 0;
}
