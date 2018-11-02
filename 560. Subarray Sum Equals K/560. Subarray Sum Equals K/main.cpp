//
//  main.cpp
//  560. Subarray Sum Equals K
//
//  Created by Jie Lu on 2018/7/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// from BBS
// The main idea is to use Prefix Sum and map
int subarraySum(vector<int>& nums, int k) {
    int count = 0, sum = 0;
    unordered_map<int, int> m;
    for(auto x: nums){
        m[sum]++;
        sum += x;
        if(m.find(sum - k) != m.end()) {
            count += m[sum - k];
            // sum is the sum of numbers from nums[0] to current position nums[i]
            // m[sum-k] is the number of indicies whose prefix sum equals to sum-k.
            // Thus, all subarrays starting from those indicies to current position have a sum equals to k.
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,1,2,1};
    cout<<subarraySum(nums, 3)<<endl;
    return 0;
}
