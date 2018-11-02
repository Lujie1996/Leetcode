//
//  main.cpp
//  228. Summary Ranges
//
//  Created by Jie Lu on 2018/5/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    int low = 0, high = 0, n = (int)nums.size();
    vector<string> res;
    while (high < n) {
        low = high;
        high++;
        while (high < n && nums[high] - nums[high-1] == 1) {
            high++;
        }
        if (low == high - 1) {
            res.push_back(to_string(nums[low]));
        }
        else {
            res.push_back(to_string(nums[low]) + "->" + to_string(nums[high-1]));
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {0,2,3,4,6,8,9};
    vector<int> nums(a, a+7);
    vector<string> res = summaryRanges(nums);
    for (string s : res) {
        cout<<s<<endl;
    }
    return 0;
}
