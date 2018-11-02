//
//  main.cpp
//  163. Missing Ranges
//
//  Created by Jie Lu on 2018/9/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string getRange(long lower, long upper){
    return (lower== upper) ? to_string(lower) : to_string(lower)+"->"+to_string(upper);
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    long next= lower; //need to declare long to avoid overflow
    
    for (int i= 0; i< nums.size(); i++) {
        if (nums[i] < next)
            continue;
        if (nums[i] == next) {
            next++;
            continue;
        }
        res.push_back(getRange(next, nums[i]-1));
        next = (long)nums[i] + 1; //need to declare long to avoid overflow
    }
    if (next <= upper)
        res.push_back(getRange(next, upper));
    
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums;
    
    vector<string> res = findMissingRanges(nums, INT_MIN, INT_MAX);
    for (auto a : res) {
        cout<<a<<endl;
    }
    return 0;
}
