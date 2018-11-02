//
//  main.cpp
//  421. Maximum XOR of Two Numbers in an Array
//
//  Created by Jie Lu on 2018/7/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// This is a very good problem. Has many totally different but very interesting ways to solve it.

// O(n^2) solution, TLE for the last test case.
//int findMaximumXOR(vector<int>& nums) {
//    int res = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        for (int j = i + 1; j < nums.size(); j++) {
//            res = max(res, nums[i] ^ nums[j]);
//        }
//    }
//    return res;
//}

// O(n) solution from Discuss. Beats 40%
int findMaximumXOR(vector<int>& nums) {
    int max = 0, mask = 0;
    for(int i = 31; i >= 0; i--) {
        mask = mask | (1 << i);
        // mask to get the most significant (32-i) bits
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num & mask);
        }
        int tmp = max | (1 << i);
        // tmp is the possible maximum XOR result considering only most significant (32-i) bits
        for(int prefix : set){
            if(set.find(tmp ^ prefix) != set.end()) {
                // Important property: if A ^ B = C, then A ^ B ^ B = C ^ B, then A = C ^ B
                // if tmp ^ prefix = A, then A ^ prefix = tmp, that is there are numbers which XOR gets tmp
                max = tmp;
                break;
            }
        }
    }
    return max;
    /*
     To think deeper into this solution, it is actually very similar to the brute force O(n^2) solution.
     It uses set.find() to save time from O(n^2) to O(n). (unordered_set is implemented based on hash table, has O(1) search time)
     To use set.find() requires a trick, which is the previous mentioned XOR property.
     You don't try every number pair to get the max, instead you set a possible max (max in a certain bit range) and use set.find() to test whether this possible max could stand.
     */
}

int main(int argc, const char * argv[]) {
    vector<int> nums{3, 10, 5, 25, 2, 8};
    cout<<findMaximumXOR(nums)<<endl;
    return 0;
}
