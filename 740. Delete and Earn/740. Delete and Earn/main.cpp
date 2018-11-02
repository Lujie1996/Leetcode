//
//  main.cpp
//  740. Delete and Earn
//
//  Created by Jie Lu on 2018/9/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int preMax = 0, curMax = 0, count = 0, preNum = 0;
    // (nums is already sorted)
    // say current nums[i] == n,
    // preMax records the max earn until n - 2 (inclusive)
    // curMax records the max earn until n - 1 (inclusive)
    // count records the number of different numbers which have been traversed
    // preNum records the last different number that is traversed
    
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0; // records the sum of all numbers which are same as nums[i]
        count++;
        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            sum += nums[i++];
        }
        sum += nums[i]; // push i to the last position of all the same numbers
        
        if (nums[i] - preNum > 1) {
            preMax = curMax;
        }
        preNum = nums[i];
        
        int thisMax = max(preMax + sum, curMax); // DP is here
        preMax = curMax;
        curMax = thisMax;
    }
    return curMax;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3,4,2};
    cout<<deleteAndEarn(nums)<<endl;
    return 0;
}
