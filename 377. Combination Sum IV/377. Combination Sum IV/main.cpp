//
//  main.cpp
//  377. Combination Sum IV
//
//  Created by Jie Lu on 2018/7/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This is my first submission, which is incorrenct, since I forgot the definition:
// Note that different sequences are counted as different combinations.
//int combinationSum4(vector<int>& nums, int target) {
//    vector<int> dp(target + 1, 0);
//    dp[0] = 1;
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[i] <= target) {
//            dp[nums[i]] = 1;
//        }
//    }
//    for (int i = 1; i <= target; i++) {
//        int count = dp[i];
//        for (int j = 0; j < i / 2; j++) {
//            count += dp[j] * dp[i-j];
//        }
//        if ((i & 1) == 0) {
//            // i is an even number
//            count += dp[i/2] * (dp[i/2] - 1);
//        }
//        dp[i] = count;
//    }
//    return dp[target];
//}

// This is my second submission, which is accepted but pretty slow (beats 2%)
// Actually the idea is right, that is to use DP and use this loop:
// for(i in 1..target)
//     for(j in 1..i-1) {let j be the first number of this sequence, so there are dp[i-j] such combinations}
// The differentce between this solution and the below beating 100% solution is implementation.
// I used hasNum to record, which can be optimized by iterate nums[j] in the inner for loop (see the 3rd solution below).
//int combinationSum4(vector<int>& nums, int target) {
//    vector<int> dp(target + 1, 0), hasNum(target + 1, 0);
//    dp[0] = 1;
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[i] <= target) {
//            dp[nums[i]] = 1;
//            hasNum[nums[i]] = 1;
//        }
//    }
//    for (int i = 2; i <= target; i++) {
//        int count = dp[i];
//        for (int j = 1; j < i; j++) {
//            // let j be the first number
//            if (hasNum[j]) {
//                count += dp[i-j];
//            }
//        }
//        dp[i] = count;
//    }
//    return dp[target];
//}

// This solution is from BBS, which beats 100%
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}
int main(int argc, const char * argv[]) {
    vector<int> nums{3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
//    vector<int> nums{1,2,3};
    cout<<combinationSum4(nums, 10)<<endl;
    return 0;
}
