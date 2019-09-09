//
//  main.cpp
//  16. 3Sum Closest
//
//  Created by Jie Lu on 2019/1/11.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3)
        return 0;
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if (first > 0 && nums[first] == nums[first-1])
            continue;
        int second = first+1, third = nums.size()-1;
        while(second < third) {
            int curSum = nums[first] + nums[second] + nums[third];
            if(curSum == target)
                return curSum;
            if (abs(target-curSum) < abs(target-closest)) {
                closest = curSum;
            }
            if (curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}

int func(const string& s) {
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<func("abc")<<endl;
    return 0;
}
