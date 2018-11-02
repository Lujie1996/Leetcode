//
//  main.cpp
//  561. Array Partition I
//
//  Created by Jie Lu on 2018/7/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size() - 1; i += 2) {
        sum += nums[i];
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,4,2,3};
    cout<<arrayPairSum(nums)<<endl;
    return 0;
}
