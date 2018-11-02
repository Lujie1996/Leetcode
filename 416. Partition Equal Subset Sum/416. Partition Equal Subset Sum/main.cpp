//
//  main.cpp
//  416. Partition Equal Subset Sum
//
//  Created by Jie Lu on 2018/7/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

/*
 This is a very import problem. Two ways to solve this:
    1. DP (normal and bitset implementations)
    2. Recursive
 Using recursive idea is similar to the problem 'Combination Sum'
 Solving it using DP is the most valuable training of coding skill.
 This problem is the warm-up for LC698.Partition to K Equal Sum Subsets
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


// DP solution, very smart!!!
//bool canPartition(vector<int>& nums) {
//    int sum = accumulate(nums.begin(), nums.end(), 0), target = sum / 2;
//    if (sum % 2 == 1)
//        return false;
//    vector<bool> dp(target + 1, false);
//    // dp[i]: wether i is a sum of any subset of nums
//    dp[0] = true;
//    for (int num : nums) {
//        for (int i = target; i >= num; i--) {
//            dp[i] = dp[i] || dp[i - num];
//            // iterate from top to down to avoid using one number for multiple times.
//            // say a number is 1, in this case all dp[i] will be true.
//            // The idea is to find all indicies which dp[i] == true and update all dp[i+num], set them to true.
//            // But its in-place implementation can be hard, since you cannot fix the above problem.
//            // Using bitset can elegantly deal with this, see code below.
//        }
//    }
//    return dp[target];
//}

// DP solution using bitset
bool canPartition(vector<int>& nums) {
    bitset<5001> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
        return false;
    }
    for (int num : nums)
        bits |= bits << num;
    return bits[sum >> 1];
}

// The same idea with that of the problem 'Combination Sum'
//bool canPartitionHelper(vector<int>& nums, int start, int target) {
//    if (target < 0)
//        return false;
//    if (target == 0)
//        return true;
//    for (int i = start; i < nums.size(); ++i) {
//        if (i != start && nums[i] == nums[i-1]) {
//            continue;
//        }
//        if (canPartitionHelper(nums, i + 1, target - nums[i]))
//            return true;
//    }
//    return false;
//}
//bool canPartition(vector<int>& nums) {
//    int sum = accumulate(nums.begin(), nums.end(), 0);
//    if (sum % 2 != 0)
//        return false;
//    sort(nums.begin(), nums.end());
//    return canPartitionHelper(nums, 0, sum / 2);
//}

int main(int argc, const char * argv[]) {
    vector<int> nums{1, 5, 11, 5};
    if (canPartition(nums)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
