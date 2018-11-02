//
//  main.cpp
//  384. Shuffle an Array
//
//  Created by Jie Lu on 2018/10/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    void swapAt(vector<int>& res, int i, int j) {
        int tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
    }
    /** Returns a random shuffling of the array. */
    // Fisher-Yates algorithm. Just remember this idea.
    vector<int> shuffle() {
        vector<int> res = nums;
        for (int i = 0; i < nums.size(); i++) {
            swapAt(res, i, i + rand() % (nums.size() - i));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
