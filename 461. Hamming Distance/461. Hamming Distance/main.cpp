//
//  main.cpp
//  461. Hamming Distance
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        res += (x & 1) ^ (y & 1);
        x >>= 1;
        y >>= 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<hammingDistance(1, 4)<<endl;
    return 0;
}
