//
//  main.cpp
//  689. Maximum Sum of 3 Non-Overlapping Subarrays
//
//  Created by Jie Lu on 2018/11/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getLeftSum(vector<pair<int,int>>& res, vector<int>& nums, int k) {
    int sum = 0, maxSum = 0, index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) {
            sum += nums[i];
            res[i] = {sum, i};
            continue;
        }
        sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
            index = i;
        }
        res[i] = {maxSum, index};
        sum -= nums[i-k+1];
    }
}

void getRightSum(vector<pair<int,int>>& res, vector<int>& nums, int k) {
    int sum = 0, maxSum = 0, index = 0;
    for (int i = (int)nums.size()-1; i>= 0; i--) {
        if (i > nums.size() - k) {
            sum += nums[i];
            res[i] = {sum, i};
            continue;
        }
        sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
            index = i;
        }
        res[i] = {maxSum, index};
        sum -= nums[i+k-1];
    }
}

// Beat 99%
// Use a k-size window to scan nums. Maintain variable maxSum and reocrd index to res.
// The window covers nums[i:k], so every scan we need to find the k-size subarray at both sides of nums[0:i] and nums[i+k:] that yields the maximum sum.
// To do that, use two dp vector<pair<int,int>>: leftSum and rightSum.
// leftSum[i] means for all k-size windows in nums[0:i] (including nums[i]),
//     1) pair.first denotes the max window sum and 2) pair.second denotes the right boundary of that window(inclusive)
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<pair<int,int>> leftSum(nums.size()), rightSum(nums.size());
    getLeftSum(leftSum, nums, k);
    getRightSum(rightSum, nums, k);
    
    vector<int> res(3,0);
    int maxSum = 0, midSum = 0;
    for (int i = k; i < 2 * k - 1; i++) {
        midSum += nums[i];
    }
    for (int i = k; i + 2*k <= nums.size(); i++) {
        midSum += nums[i+k-1];
        if (i < k) {
            continue;
        }
        int sum = leftSum[i-1].first + rightSum[i+k].first + midSum;
        if (sum > maxSum) {
            maxSum = sum;
            res[0] = leftSum[i-1].second - k + 1;
            res[1] = i;
            res[2] = rightSum[i+k].second;
        }
        midSum -= nums[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{20,18,9,2,14,1,10,3,11,18};
    vector<int> res = maxSumOfThreeSubarrays(nums, 3);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
