//
//  main.cpp
//  910. Smallest Range II
//
//  Created by Jie Lu on 2018/10/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Observation 1. -K/+K is equal to +0/+2K
// Observation 2. after sorting A, for a +0/+2K plan to A that could possibly results in the minimum range,
//  there must exist a index(pivot) so that all numbers to its left +2K and all numbers to its right(including itself) +0
// In implementation, iterative every position in array and assume it to be the pivot. Keep updating the minimum range.
int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int mx = INT_MAX, mn = INT_MIN, res = A[A.size()-1] - A[0];
    for (int i = 1; i < A.size(); i++) {
        mx = max(A[i-1] + 2 * K, A[A.size()-1]);
        mn = min(A[0] + 2 * K, A[i]);
        res = min(res, mx-mn);
    }
    return min(res, A[A.size()-1] - A[0]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
