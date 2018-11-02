//
//  main.cpp
//  643. Maximum Average Subarray I
//
//  Created by Jie Lu on 2018/8/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    maxSum = sum;
    for (int i = k; i < nums.size(); i++) {
        sum -= nums[i-k];
        sum += nums[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum * 1.0 / k;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,12,-5,-6,50,3};
    cout<<findMaxAverage(nums, 4)<<endl;
    return 0;
}
