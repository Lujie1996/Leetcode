//
//  main.cpp
//  1. Two Sum
//
//  Created by Jie Lu on 2019/8/28.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numIndex;
    for (int i = 0; i < nums.size(); i++) {
        numIndex[nums[i]] = i;
    }
    
    for (auto row : numIndex) {
        auto it = numIndex.find(target - row.first);
        if (it != numIndex.end() && it->second != row.second) {
            return {row.second, it->second};
        }
    }
    return {};
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3,4};
    auto res = twoSum(nums, 7);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
