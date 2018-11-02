//
//  main.cpp
//  41. First Missing Positive
//
//  Created by Jie Lu on 2018/9/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; ++ i)
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);
    
    for (int i = 0; i < n; ++ i)
        if (nums[i] != i + 1)
            return i + 1;
    
    return n + 1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3,4,-1,1};
    cout<<firstMissingPositive(nums)<<endl;
    return 0;
}
