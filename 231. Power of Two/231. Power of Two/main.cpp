//
//  main.cpp
//  231. Power of Two
//
//  Created by Jie Lu on 2018/5/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    int i = 0, count = 0;
    while (i++ < 32) {
        if ((n & 0x1) == 1) {
            count++;
        }
        n >>= 1;
    }
    return count == 1 ? true : false;
}

//Another solution :
//bool isPowerOfTwo(int n) {
//    if(n>0&&(n&(n-1))==0)
//        return true;
//    else
//        return false;
//}
int main(int argc, const char * argv[]) {
    int x;
    while (cin>>x) {
        if (isPowerOfTwo(x))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    
    return 0;
}
