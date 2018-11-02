//
//  main.cpp
//  698. Partition to K Equal Sum Subsets
//
//  Created by Jie Lu on 2018/7/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// Recursive solution
bool canPartition(vector<int> nums, vector<bool> visited, int curSum, int target, int start, int k) {
    if (k == 1) {
        return true;
    }
    if (curSum == target) {
        return canPartition(nums, visited, 0, target, 0, k - 1);
    }
    for (int i = start; i < nums.size(); i++) {
        if (!visited[i] && nums[i] + curSum <= target) {
            curSum += nums[i];
            visited[i] = true;
            if (canPartition(nums, visited, curSum, target, i + 1, k)) {
                return true;
            }
            curSum -= nums[i];
            visited[i] = false;
        }
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<bool> visited(nums.size(), false);
    if (sum % k) {
        return false;
    }
    return canPartition(nums, visited, 0, sum / k, 0, k);
}

int main(int argc, const char * argv[]) {
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    if (canPartitionKSubsets(nums, 4)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
