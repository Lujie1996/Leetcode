//
//  main.cpp
//  357. Count Numbers with Unique Digits
//
//  Created by Jie Lu on 2018/7/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 when n is 0, it is clear that there is just one number 0.
 
 when n is 1, it is trivial that there are 10 numbers: 0,1,2...9.
 
 when n is 2, the range is [0, 99]. The total unique digits is divided to two part: just one digit or two digit.
 
 **dp[2]  = dp[1] + the combination with  two digits.**
 '0' could only be at unit digit. so when '0' is at unit digit, there are 9 kinds of. when there is no '0', there are 9 kinds of numbers at tens digit, and 8 kinds of numbers at unit digit. So the combination with two digits are: 9 + 9*8 is equal to
 
 9 * (1+8) = 9 * 9.
 when n is 3, the range is [0, 999]. The total unique digits is divided to two part: less than 3 digit or 3 digit.
 
 **dp[3]  = dp[2] + the combination with  3 digits.**
 '0' could only be at unit digit and ten's digit.
 
 When '0' is at unit digit, there are 9 * 8 kind of numbers(9 is the kind of numbers at hundred's digit, 8 is the kind of numbers at ten's digit);
 
 When '0' is at ten's digit, there are 9 * 8 kind of numbers(9 is the kind of numbers at hundred's digit, 8 is the kind of numbers at unit digit);
 
 When there is no '0', there are 9 * 8 * 7 kinds of numbers(9 is the kind of numbers at hundred's digit, 8 is the kind of numbers at ten's digit, 7 is the kind of numbers at unit digit).
 
 So there are:
 
 9 * 8  + 9 * 8 + 9 * 8 * 7  = 9 * 8 * (1 + 1 + 8 ) = 9 * 9 * 8
 kinds of combinations with three digits.
 
 .........
 */
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 0;
    }
    int dp = 10;
    for (int i = 2; i <= n; i++) {
        int count = 9, multi = 9;
        for (int j = 0; j < i - 1; j++) {
            count *= multi;
            multi--;
        }
        dp = dp + count;
    }
    return dp;
}
int main(int argc, const char * argv[]) {
    for (int i = 1; i < 8; i++) {
        cout<<countNumbersWithUniqueDigits(i)<<" ";
        // 10 91 739 5275 32491 168571 712891
    }
    cout<<endl;
    return 0;
}
