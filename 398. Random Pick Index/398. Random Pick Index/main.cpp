//
//  main.cpp
//  398. Random Pick Index
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums;
    
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        // explaination: https://leetcode.com/problems/random-pick-index/discuss/88071/C++_Time:-O(n)-Space:-O(n)_116ms_96.41_with-clear-explanation-by-probability
        
        int nTarget = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                nTarget += 1;
                if (rand() % nTarget == 0) {
                    res = i;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
