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

int tryOneSide(unordered_set<int>& hash, int pos, int bias) {
    int t = pos, count = 0;
    while (true) {
        t += bias;
        if (hash.find(t) != hash.end()) {
            count += 1;
            hash.erase(t);
        }
        else
            break;
    }
    return count;
}

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    unordered_set<int> hash(nums.begin(), nums.end());
    
    int maxLen = INT_MIN;
    for (int num : hash) {
        int count = tryOneSide(hash, num, 1) + tryOneSide(hash, num, -1) + 1;
        maxLen = max(maxLen, count);
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(a,a+6);
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}
