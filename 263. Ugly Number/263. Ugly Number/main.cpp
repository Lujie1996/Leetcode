//
//  main.cpp
//  263. Ugly Number
//
//  Created by Jie Lu on 2018/5/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

/*
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 */

#include <iostream>
using namespace std;

bool isUgly(int num) {
    for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
    return num == 1;
}

int main(int argc, const char * argv[]) {
    int num;
    while (cin>>num) {
        if (isUgly(num)) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
