//
//  main.cpp
//  55. Jump Game
//
//  Created by Jie Lu on 11/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
    Why always try the max step? Say you have nums = [6,2,2,0,0,0,1], 
    and you jump 2 on the first jump. Since we are doing every try from 
    ith position, if we jump 2 steps to nums[2], we will eventually get 
    there in the one-by-one iteration. Only when jump max steps could make
    a difference here.
*/
bool canJump(vector<int>& nums){
    int maxLen=0;
    for(int i=0;i<nums.size()&&i<=maxLen;i++){
        int far=i+nums[i];
        while(far<nums.size()&&nums[far]!=0){
            far+=nums[far];
        }
        maxLen=max(maxLen,far);
        if(maxLen>=nums.size()-1)
            return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int tmp[]={1,1,2,2,0,1,1};
    vector<int> nums(tmp,tmp+7);
    if(canJump(nums))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
