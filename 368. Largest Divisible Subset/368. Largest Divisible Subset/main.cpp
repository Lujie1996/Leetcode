//
//  main.cpp
//  368. Largest Divisible Subset
//
//  Created by Jie Lu on 2018/7/20.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Very good LC problem!
 I used half an hour but didn't solved it.
 This solution is from BBS and beats 96% submissions.
 
 DP solution:
 first, sort the vector in ascending order.
 dp[i]: size of the LDS(LargestDivisibleSubset) whose max number is nums[i]
    define: dp[i] = max{dp[j] + 1 | j < i and nums[i] % nums[j] == 0}, if none, dp[i] = 1
 use preNum[i] to trace the index of the next number which is smaller than nums[i]
 finally use preNum to get the return result.
 */
vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    if (nums.size() == 0) {
        return res;
    }
    int n = (int)nums.size(), maxSize = 0, maxSizeIndex = 0;
    vector<int> dp(n, 1), preNum(n, -1);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    preNum[i] = j;
                }
            }
        }
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxSizeIndex = i;
        }
    }
    while (maxSizeIndex != -1) {
        res.push_back(nums[maxSizeIndex]);
        maxSizeIndex = preNum[maxSizeIndex];
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{4,8,10,240};
    vector<int> res = largestDivisibleSubset(nums);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
