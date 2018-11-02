//
//  main.cpp
//  136. Single Number
//
//  Created by Jie Lu on 2018/4/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {4,1,2,1,2};
    vector<int> nums(a,a+5);
    cout<<singleNumber(nums)<<endl;
    return 0;
}
