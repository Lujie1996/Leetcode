//
//  main.cpp
//  279. Perfect Squares
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//int numSquares(int n) {
//    vector<int> dp(n+1, n);
//    dp[0] = 0;
//    for (int i = 1; i <= n; i++) {
//        int count = 0;
//        for (int j = 1; j * j <= i; j++) {
//            count = min(count, dp[i-j*j] + 1);
//        }
//        dp[i] = count;
//    }
//    return dp[n];
//}

// The idea of this solution is actually the same as the above one.
// This solution uses only 10ms while the above one takes more than 100ms.
// The only difference in implementation is that this solution uses static vector instead of vector.
// Since the Leetcode OJ platform needs to call this function many times to go through all test cases,
// using static could save a lot more time in the initialization of vector.
// But anyway, this advantage only exists in OJ environment.
int numSquares(int n)
{
    static vector<int> cntPerfectSquares({0});
    while (cntPerfectSquares.size() <= n)
    {
        int m = (int)cntPerfectSquares.size();
        int cntSquares = INT_MAX;
        for (int i = 1; i*i <= m; i++)
        {
            cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
        }
        
        cntPerfectSquares.push_back(cntSquares);
    }
    return cntPerfectSquares[n];
}

int main(int argc, const char * argv[]) {
    cout<<numSquares(12)<<endl;
    return 0;
}
