//
//  main.cpp
//  326. Power of Three
//
//  Created by Jie Lu on 2018/7/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
//    int maxPow = 1;
//    while (maxPow < maxPow * 3) {
//        maxPow *= 3;
//    }
//    cout<<maxPow<<endl;
    int maxPow = 1162261467;
    if (n > 0 && maxPow % n == 0) {
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    if (isPowerOfThree(27)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
