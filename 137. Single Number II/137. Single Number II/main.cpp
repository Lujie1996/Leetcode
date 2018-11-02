//
//  main.cpp
//  137. Single Number II
//
//  Created by Jie Lu on 2018/4/23.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    /*
     The code seems tricky and hard to understand at first glance.
     However, if you consider the problem in Boolean algebra form, everything becomes clear.
     
     What we need to do is to store the number of '1’s of every bit. Since each of the 32 bits follow the same rules,we just need to consider 1 bit.
     We know a number appears 3 times at most, so we need 2 bits to store that. Now we have 4 state, 00, 01, 10 and 11, but we only need 3 of them.
     
     In this solution, 00, 01 and 10 are chosen. Let ‘ones’ represents the first bit, ‘twos’ represents the second bit.
     Then we need to set rules for ‘ones’ and ‘twos’ so that they act as we hopes. The complete loop is 00->10->01->00(0->1->2->3/0).
     
     For ‘ones’, we can get ‘ones = ones ^ A[i]; if (twos == 1) then ones = 0’, that can be tansformed to ‘ones = (ones ^ A[i]) & ~twos’.
     
     Similarly, for ‘twos’, we can get ‘twos = twos ^ A[i]; if (ones* == 1) then twos = 0’ and ‘twos = (twos ^ A[i]) & ~ones’.
     Notice that ‘ones*’ is the value of ‘ones’ after calculation, that is why twos is calculated later.
     */
    int ones = 0, twos = 0;
    for(int i = 0; i < nums.size(); i++){
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}

//Code below follows the same idea as above, but has a more intuitive implementation that is easier to come up with.
// int singleNumber(vector<int>& nums) {
//    int res = 0;
//    for (int i = 0; i < 32; i++) {
//        int sum = 0;
//        for (int j = 0; j < nums.size(); j++) {
//            if (((nums[j] >> i) & 1) == 1) {
//                sum += 1;
//                sum %= 3;
//            }
//        }
//        if (sum) {
//            res |= sum << i;
//        }
//    }
//    return res;
// }
int main(int argc, const char * argv[]) {
    int a[] = {2,2,2,3};
    vector<int> nums(a,a+4);
    cout<<singleNumber(nums)<<endl;
    return 0;
}
