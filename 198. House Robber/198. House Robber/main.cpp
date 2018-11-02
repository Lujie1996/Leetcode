//
//  main.cpp
//  198. House Robber
//
//  Created by Jie Lu on 2018/4/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return nums[0];
    }
    if (n == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
    }
    return max(dp[n-2], dp[n-1]);
}
int main(int argc, const char * argv[]) {
    int a[] = {2,7,9,3,1};
    vector<int> nums(a, a+5);
    cout<<rob(nums)<<endl;
    return 0;
}
