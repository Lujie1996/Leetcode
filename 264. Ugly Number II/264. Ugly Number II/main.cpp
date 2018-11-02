//
//  main.cpp
//  264. Ugly Number II
//
//  Created by Jie Lu on 2018/5/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then
 k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:
 k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
 */

int nthUglyNumber(int n) {
    int c2, c3, c5, i, t1, t2, t3;
    c2 = c3 = c5 = 1;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for (i = 2; i <= n; i++) {
        t1 = 2 * dp[c2];
        t2 = 3 * dp[c3];
        t3 = 5 * dp[c5];
        dp[i] = min(t1, min(t2, t3));
        if (dp[i] == t1) {
            c2++;
        }
        if (dp[i] == t2) {
            c3++;
        }
        if (dp[i] == t3) {
            c5++;
        }
    }
    return dp[n];
}
int main(int argc, const char * argv[]) {
    int num;
    while (cin>>num) {
        cout<<nthUglyNumber(num)<<endl;
    }
    return 0;
}
