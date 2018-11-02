//
//  main.cpp
//  413. Arithmetic Slices
//
//  Created by Jie Lu on 2018/7/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    int i = 0, j = 0, n = (int)nums.size(), diff = 0, res = 0;
    while (i < n && j < n) {
        j = i + 1;
        diff = nums[j] - nums[j-1];
        j++;
        while (j < n && nums[j] - nums[j-1] == diff) {
            j++;
        }
        if (j - i == 2 && j < n) {
            i++;
        }
        else {
            int k = j - i;
            res += (k * k - 3 * k + 2) / 2;
        }
        i = j;
    }
    return res;
}

// DP solution
//int numberOfArithmeticSlices(vector<int>& A) {
//    int n = (int)A.size();
//    if (n < 3) return 0;
//    vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i]
//    if (A[2] - A[1] == A[1] - A[0])
//        dp[2] = 1; // if the first three numbers are arithmetic or not
//    int result = dp[2];
//    for (int i = 3; i < n; ++i) {
//        if (A[i] - A[i-1] == A[i-1] - A[i-2])
//            dp[i] = dp[i-1] + 1;
//        result += dp[i]; // accumulate all valid slices
//    }
//    return result;
//}
int main(int argc, const char * argv[]) {
    vector<int> A{-2,-9,1,2,3,4,5,6,7,10,11,12,15};
    cout<<numberOfArithmeticSlices(A)<<endl;
    for (int i = 1; i < 10; i++) {
        cout<<i<<": "<<(i * i - 3 * i + 2) / 2<<endl;
    }
    return 0;
}
