//
//  main.cpp
//  303. Range Sum Query - Immutable
//
//  Created by Jie Lu on 2018/5/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> nums) {
        sums.resize(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i-1];
    }
};
int main(int argc, const char * argv[]) {
    int a[] = {-2, 0, 3, -5, 2, -1};
    vector<int> nums(a, a+6);
    NumArray test(nums);
    cout<<test.sumRange(0, 2)<<endl;
    cout<<test.sumRange(2, 5)<<endl;
    cout<<test.sumRange(0, 5)<<endl;
    return 0;
}
