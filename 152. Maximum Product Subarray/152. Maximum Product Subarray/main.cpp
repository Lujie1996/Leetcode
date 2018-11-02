//
//  main.cpp
//  152. Maximum Product Subarray
//
//  Created by Jie Lu on 13/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    vector<int> dpmin(nums.size()+1,0),dpmax(nums.size()+1,0);
    dpmin[0]=dpmax[0]=1;
    int maxP=INT_MIN;
    for(int i=0;i<nums.size();i++){
        dpmin[i+1]=min(min(dpmin[i]*nums[i],dpmax[i]*nums[i]),nums[i]);
        dpmax[i+1]=max(max(dpmin[i]*nums[i],dpmax[i]*nums[i]),nums[i]);
        maxP=max(maxP,dpmax[i+1]);
    }
    return maxP;
}
int main(int argc, const char * argv[]) {
    int a[]={2,-5,-2,-4,3};
    vector<int> nums(a,a+5);
    cout<<maxProduct(nums)<<endl;
    return 0;
}
