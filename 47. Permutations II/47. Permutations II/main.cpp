//
//  main.cpp
//  47. Permutations II
//
//  Created by Jie Lu on 07/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myPermute(vector<int> nums, vector<vector<int>>& res, int startPos){
    if(startPos==nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i=startPos;i<nums.size();i++){
        if(i!=startPos&&nums[i]==nums[startPos])
            continue;
        swap(nums[i],nums[startPos]);
        myPermute(nums,res,startPos+1);
        //myPermute函数不能用引用传递传nums，这一点和Permutation那道题不同
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    myPermute(nums, res, 0);
    return res;
}
int main(int argc, const char * argv[]){
    int a[] = {2,2,1,1};
    vector<int> nums(a,a+4);
    vector<vector<int>> res = permuteUnique(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
