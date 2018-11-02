//
//  main.cpp
//  219. Contains Duplicate II
//
//  Created by Jie Lu on 2018/4/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> intMap; // num - index
    unordered_map<int, int> :: iterator it;
    int thisInt;
    for (int i = 0; i < nums.size(); i++) {
        thisInt = nums[i];
        it = intMap.find(thisInt);
        if (it == intMap.end()) {
            intMap[thisInt] = i;
            continue;
        }
        if (i - it->second <= k) {
            return true;
        }
        else {
            intMap[thisInt] = i;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
//    int a[] = {0,1,2,3,4,5,6,3,8,9};
    int a[] = {1, 0, 1, 1};
//    vector<int> nums(a, a+10);
    vector<int> nums(a, a+4);
    if (containsNearbyDuplicate(nums, 1)) {
        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}
