//
//  main.cpp
//  128. Longest Consecutive Sequence
//
//  Created by Jie Lu on 2018/4/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 Use hashset.
 Traverse the vector, for current number, probe numbers in both directions,
 while (num in hashset) {
     erase num in hashset,
     num += 1;
     // num -= 1;
     record current length of consecutive sequence
 }
 */

find the longest ajacent
int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    
    unordered_set<int> hash(nums.begin(), nums.end());
    int bias, t, count, maxLen;
    maxLen = INT_MIN;
    for (int num : hash) {
        if (hash.find(num) == hash.end()) {
            continue;
        }
        bias = count = 1;
        while (true) {
            t = num + bias;
            if (hash.find(t) != hash.end()) {
                count += 1;
                bias += 1;
                hash.erase(t);
            }
            else
                break;
        }
        bias = 1;
        while (true) {
            t = num - bias;
            if (hash.find(t) != hash.end()) {
                count += 1;
                bias += 1;
                hash.erase(t);
            }
            else
                break;
        }
        maxLen = count > maxLen ? count : maxLen;
    }
    return maxLen;
}
int main(int argc, const char * argv[]) {
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(a,a+6);
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}
