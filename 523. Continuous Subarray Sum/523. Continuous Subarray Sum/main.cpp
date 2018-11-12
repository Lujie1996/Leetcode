//
//  main.cpp
//  523. Continuous Subarray Sum
//
//  Created by Jie Lu on 2018/11/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> modIndex;
    modIndex[0] = -1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (k != 0) {
            sum %= k;
        }
        auto it = modIndex.find(sum);
        if (it != modIndex.end()) {
            if (i - it->second >= 2) {
                return true;
            }
        }
        else {
            modIndex[sum] = i;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
