//
//  main.cpp
//  45. Jump Game II
//
//  Created by Jie Lu on 2018/9/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    int curEnd = 0, far = 0, step = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        far = max(far, i + nums[i]);
        if (i == curEnd) {
            curEnd = far;
            step += 1;
        }
    }
    return step;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{2,3,1,1,4};
    cout<<jump(nums)<<endl;
    return 0;
}
