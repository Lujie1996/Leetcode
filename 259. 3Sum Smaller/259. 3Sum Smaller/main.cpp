//
//  main.cpp
//  259. 3Sum Smaller
//
//  Created by Jie Lu on 2018/6/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1, k = (int)nums.size() - 1;
        if (nums[i] + nums[i+1] + nums[i+2] >= target) {
            break;
        }
        while (j < k) {
            if (nums[i] + nums[j] +nums[j+1] >= target) {
                break;
            }
            while (j < k && nums[i] + nums[j] +nums[k] >= target) {
                k--;
            }
            res += k - j;
            j++;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{0,1,1,2,2,3};
    cout<<threeSumSmaller(nums, 5)<<endl;
    // 0,1,1  0,1,2  0,1,3  0,2,2
    return 0;
}
