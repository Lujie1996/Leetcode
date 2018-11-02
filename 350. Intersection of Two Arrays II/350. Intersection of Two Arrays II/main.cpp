//
//  main.cpp
//  350. Intersection of Two Arrays II
//
//  Created by Jie Lu on 2018/6/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> numCnt;
    for (auto num : nums1)
        numCnt[num]++;
    vector<int> res;
    for (auto num : nums2)
        if (numCnt.find(num) != numCnt.end() && numCnt[num] > 0) {
            res.push_back(num);
            numCnt[num]--;
        }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> nums1{1,2,2,1}, nums2{2,2};
    vector<int> res = intersect(nums1, nums2);
    for (auto num : res)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
