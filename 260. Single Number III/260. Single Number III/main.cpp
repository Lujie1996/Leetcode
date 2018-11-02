//
//  main.cpp
//  260. Single Number III
//
//  Created by Jie Lu on 2018/5/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

/*
 Given an array of numbers nums, in which exactly two elements appear only once and
 all the other elements appear exactly twice. Find the two elements that appear only once.
 
 For example:
 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 */

#include <iostream>
#include <vector>
using namespace std;


/*
 The two numbers that appear only once must differ at some bit, this is how we can distinguish between them. Otherwise, they will be one of the duplicate numbers.
 
 One important point is that by XORing all the numbers, we actually get the XOR of the two target numbers (because XORing two duplicate numbers always results in 0).
 Consider the XOR result of the two target numbers; if some bit of the XOR result is 1, it means that the two target numbers differ at that location.
 
 Let’s say the at the ith bit, the two desired numbers differ from each other. which means one number has bit i equaling: 0, the other number has bit i equaling 1.
 
 Thus, all the numbers can be partitioned into two groups according to their bits at location i.
 the first group consists of all numbers whose bits at i is 0.
 the second group consists of all numbers whose bits at i is 1.
 
 Notice that, if a duplicate number has bit i as 0, then, two copies of it will belong to the first group. Similarly, if a duplicate number has bit i as 1, then,
 two copies of it will belong to the second group.
 
 by XoRing all numbers in the first group, we can get the first number.
 by XoRing all numbers in the second group, we can get the second number.
 */
vector<int> singleNumber(vector<int>& nums) {
    vector<int> res(2,0);
    int AXorB = 0;
    for (auto num : nums) {
        AXorB ^= num;
    }
    AXorB &= -AXorB;
    // get its least significant set bit. e.g., 6 & -6: 0110 & 1010 = 0010, which is the mask for LSB.
    // The AXorB &= -AXorB is just an abbreviation with the knowledge of ~(AXorB - 1) = - (AXorB - 1) - 1 = -AXorB.
    // ******This is an important trick to get the LSB of a number.******
    for (int num : nums) {
        res[(AXorB & num) == 0 ? 0 : 1] ^= num;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {1, 2, 1, 3, 2, 5};
    vector<int> nums(a, a+6);
    vector<int> res = singleNumber(nums);
    for (auto num : nums) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
