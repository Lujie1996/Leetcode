//
//  main.cpp
//  349. Intersection of Two Arrays
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> numSet;
    for (auto num : nums1) {
        numSet.insert(num);
    }
    vector<int> res;
    for (auto num : nums2) {
        if (numSet.find(num) != numSet.end()) {
            numSet.erase(num);
            res.push_back(num);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums1{1, 2, 2, 1}, nums2{2, 2};
    vector<int> res = intersection(nums1, nums2);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
