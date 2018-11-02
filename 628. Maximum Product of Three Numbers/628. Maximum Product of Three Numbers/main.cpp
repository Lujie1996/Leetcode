//
//  main.cpp
//  628. Maximum Product of Three Numbers
//
//  Created by Jie Lu on 2018/7/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maximumProduct(vector<int>& nums) {
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    // optimization: select the greatest and smallest 3 numbers, instead of sorting the whole nums.
}
int main(int argc, const char * argv[]) {
    vector<int> nums{-3,-5,1,2,3,5};
    cout<<maximumProduct(nums)<<endl;
    return 0;
}
