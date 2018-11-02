//
//  main.cpp
//  805. Split Array With Same Average
//
//  Created by Jie Lu on 2018/8/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 The DP could be described as:
 dp[i][k][s] = dp[i-1][k][s] || dp[i-1][k-1][s - A[i - 1]]
 where dp[i][k][s] means whether sum s could be achieved by summing up k numbers selected among the first n numbers in given array.
 Notice that the dp[i & 1] stuff in my code is just for saving space (otherwise you got error), which means dp[n] in above expression.
 */
//bool splitArraySameAverage(vector<int>& A) {
//    bool dp[2][16][300001];
//    int sum = 0;
//    for (auto a: A)
//        sum += a;
//    int n = (int)A.size();
//    memset(dp, 0, sizeof(dp));
//    for (int i = 0; i <= n; i++) {
//        dp[i & 1][0][0] = true;
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int k = 1; k <= n / 2; k++) {
//            for (int s = 1; s <= sum; s++) {
//                if (s >= A[i - 1]) {
//                    dp[i & 1][k][s] = dp[i-1 & 1][k][s] || dp[i-1 & 1][k-1][s - A[i - 1]];
//                } else {
//                    dp[i & 1][k][s] = dp[i-1 & 1][k][s];
//                }
//            }
//        }
//    }
//    for (int k = 1; k <= n / 2; k++) {
//        if ((k * sum / n * n == k * sum) && dp[n & 1][k][k * sum / n])
//        // k * sum / n * n == k * sum is to check if k * sum / n is an integer. Since the sum of k integers should be an integer.
//            return true;
//    }
//    return false;
//}

bool combinationSum(vector<int>& A, int sum, int n, int idx){
    if (n == 0 && sum == 0)
        return true;
    else if (n == 0)
        return false;
    int s = 0;
    for (int i = idx; i < A.size(); i++) {
        if (s + A[i] > sum)
            break;
        // essential pruning to avoid TLE
        if (i > idx && A[i] == A[i - 1])
            continue;
        if (combinationSum(A, sum - A[i], n - 1, i + 1))
            return true;
    }
    return false;
}
bool splitArraySameAverage(vector<int>& A) {
    int n = (int)A.size(), sum = 0;
    for (int i : A)
        sum += i;
    sort(A.begin(), A.end());
    for (int k = 1; k <= n / 2; k++) {
        // k is the length of the shorter subarray
        // not too many k to be searched -> Early termination!!!
        if ((sum * k) % n == 0 && combinationSum(A, (sum * k) / n, k, 0)) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> A{1,2,3,4,5,6,7,8};
    if (splitArraySameAverage(A)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
