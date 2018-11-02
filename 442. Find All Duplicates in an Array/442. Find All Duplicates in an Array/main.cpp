//
//  main.cpp
//  442. Find All Duplicates in an Array
//
//  Created by Jie Lu on 2018/9/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++){
        nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0)
            res.push_back(abs(nums[i]));
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
