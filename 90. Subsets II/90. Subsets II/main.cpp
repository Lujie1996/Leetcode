//
//  main.cpp
//  90. Subsets II
//
//  Created by Jie Lu on 2018/4/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void genSubsets(vector<vector<int>>& res, vector<int>& cur, vector<int>& nums, int pos) {
    res.push_back(cur);
    for (int i = pos; i < nums.size(); i++) {
        if (i > pos && nums[i] == nums[i-1]) {
            continue;
        }
        cur.push_back(nums[i]);
        genSubsets(res, cur, nums, i + 1);
        cur.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    genSubsets(res, cur, nums, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    int a[] = {2,1,2};
    vector<int> nums(a,a+3);
    vector<vector<int>> res = subsetsWithDup(nums);
    for(int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
