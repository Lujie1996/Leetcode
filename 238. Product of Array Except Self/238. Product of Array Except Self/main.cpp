//
//  main.cpp
//  238. Product of Array Except Self
//
//  Created by Jie Lu on 2018/5/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int i = 0, n = (int)nums.size(), right = 1;
    vector<int> res(n, 0);
    res[0] = 1;
    for (i = 1; i < n; i++) {
        res[i] = res[i-1] * nums[i-1];
    }
    for (i = n - 2; i >= 0; i--) {
        right *= nums[i+1];
        res[i] *= right;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4};
    vector<int> nums(a, a+4);
    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
