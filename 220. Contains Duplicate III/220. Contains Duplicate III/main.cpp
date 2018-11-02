//
//  main.cpp
//  220. Contains Duplicate III
//
//  Created by Jie Lu on 2018/5/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically
    for (int i = 0; i < nums.size(); i++) {
        if (i > k)
            window.erase(nums[i-k-1]);
        int lowerBound = nums[i] < 0 && nums[i] - t > 0 ? INT_MIN : nums[i] - t;
        auto pos = window.lower_bound(lowerBound);
        if (pos != window.end() && *pos - nums[i] <= t)
            return true;
        window.insert(nums[i]);
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int a[] = {-3,3};
    vector<int> nums(a, a+2);
    if (containsNearbyAlmostDuplicate(nums, 2, 4)) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
