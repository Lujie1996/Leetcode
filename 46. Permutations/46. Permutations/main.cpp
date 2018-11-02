//
//  main.cpp
//  46. Permutations
//
//  Created by Jie Lu on 06/03/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//void nextPermute(vector<int> nums, vector<vector<int>>& res, vector<int>& cur){
//    if(nums.size()==0){
//        res.push_back(cur);
//        return;
//    }
//    vector<int> nextNums=nums, nextCur=cur;
//    for(int i=0;i<nums.size();i++){
//        nextCur.push_back(nums[i]);
//        nextNums.erase(nextNums.begin()+i);
//        nextPermute(nextNums, res, nextCur);
//        nextNums=nums;
//        nextCur=cur;
//    }
//}
//vector<vector<int>> permute(vector<int>& nums) {
//    vector<vector<int>> res;
//    vector<int> cur;
//    nextPermute(nums, res, cur);
//    return res;
//}
//
//More efficient solution:
void swap(vector<int>& nums, int i, int j) {
    int tmp=nums[i];
    nums[i]=nums[j];
    nums[j]=tmp;
}
void myPermute(vector<int>& nums, vector<vector<int>>& res, int pos) {
    if(pos==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=pos;i<nums.size();i++){
        swap(nums, i, pos);
        myPermute(nums, res, pos+1);
        swap(nums, i, pos);
        //不停的把pos后面的各个数字替换到pos的位置。观察从pos开始的子串，这个过程保证了首个位置(pos)可以是后面的任意一个只值
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    myPermute(nums, res, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    int a[]={1,2,3};
    vector<int> nums(a,a+3);
    vector<vector<int>> res=permute(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
