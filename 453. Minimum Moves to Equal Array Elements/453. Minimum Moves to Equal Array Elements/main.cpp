//
//  main.cpp
//  453. Minimum Moves to Equal Array Elements
//
//  Created by Jie Lu on 2018/7/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int minMoves(vector<int>& nums) {
    int sum = 0, minNum = INT_MAX;
    for (auto num : nums) {
        sum += num;
        minNum = min(minNum, num);
    }
    return sum - (int)nums.size() * minNum;
}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,2,3};
    cout<<minMoves(nums)<<endl;
    return 0;
}
