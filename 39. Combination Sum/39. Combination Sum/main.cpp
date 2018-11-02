//
//  main.cpp
//  39. Combination Sum
//
//  Created by Jie Lu on 05/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//
//  回溯的思路，递归实现

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void getCombination(vector<int>& candidates, vector<vector<int>>& res, vector<int>& com, int target, int start) {
    if(target==0){
        res.push_back(com);
        return;
    }
    for(int i=start;i<candidates.size();i++){
        if(candidates[i]>target)
            break;
        com.push_back(candidates[i]);
        getCombination(candidates, res, com, target-candidates[i], i);
        com.pop_back();
        //剪枝 ： 当函数从getCombination()退出的时候，要么上一步是target==0，要么是candidats[i]>target。第二种情况的推出后程序执行到上一行，这里需要把之前pushback进来的数字删除。
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> com;
    getCombination(candidates, res, com, target, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    int nums[]={2,3,6,7};
    vector<int> candidates(nums, nums+4);
    vector<vector<int>> res = combinationSum(candidates, 7);
    for(int i=0;i<res.size();i++)
    {
        for (int j=0;j<res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
