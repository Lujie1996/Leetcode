//
//  main.cpp
//  974. Subarray Sums Divisible by K
//
//  Created by Jie Lu on 2019/1/15.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int>& A, int K) {
    // map: prefixSum % K -> its occurrance
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, res = 0;
    for (auto num : A) {
        sum = (sum + num % K + K) % K;
        // sum + num + K is to avoid any negative number as key in map
        // num % K is to avoid int overflow
        res += prefixSum[sum]++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{4,5,0,-2,-3,1};
    cout<<subarraysDivByK(nums, 5)<<endl;
    return 0;
}
