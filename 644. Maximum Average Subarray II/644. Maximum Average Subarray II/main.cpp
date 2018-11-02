//
//  main.cpp
//  644. Maximum Average Subarray II
//
//  Created by Jie Lu on 2018/8/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool check(vector<int> nums, double mid, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i] - mid;
    }
    if (sum >= 0) {
        return true;
    }
    double preSum = 0, minPreSum = 0;
    //Note: initialization of minPreSum should be 0 (means that not even one number is selected), not INT_MAX.
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - mid;
        preSum += nums[i - k] - mid;
        minPreSum = min(minPreSum, preSum);
        if (sum >= minPreSum)
            return true;
    }
    return false;
}
// Idea: https://leetcode.com/problems/maximum-average-subarray-ii/solution/
double findMaxAverage(vector<int>& nums, int k) {
    double maxNum = INT_MAX, minNum = INT_MIN;
    for (auto num : nums) {
        maxNum = num > maxNum ? num : maxNum;
        minNum = num < minNum ? num : minNum;
    }
    double preMid = maxNum, error = INT_MAX;
    while (error > 0.00001) {
        double mid = (maxNum + minNum) / 2.0;
        if (check(nums, mid, k)) {
            // return true, avg needs to be bigger
            minNum = mid;
        }
        else {
            maxNum = mid;
        }
        error = fabs(preMid - mid);
        preMid = mid;
    }
    return minNum;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{8,9,3,1,8,3,0,6,9,2};
    cout<<findMaxAverage(nums, 8)<<endl;
    return 0;
}
