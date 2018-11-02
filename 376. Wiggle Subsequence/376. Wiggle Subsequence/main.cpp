//
//  main.cpp
//  376. Wiggle Subsequence
//
//  Created by Jie Lu on 13/02/2018.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if(nums.size()<=1)
        return (int)nums.size();
    vector<int> up(nums.size(),1),down(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                up[i]=max(up[i],down[j]+1);
            }
            else if(nums[j]>nums[i]){
                down[i]=max(down[i],up[j]+1);
            }
        }
    }
    return max(up.back(), down.back());
}

//Other O(n) solution:
//int wiggleMaxLength(vector<int>& nums) {
//    if(nums.size()<=1)
//        return (int)nums.size();
//    int up=1,down=1;
//    for(int i=1;i<nums.size();i++){
//        if(nums[i]>nums[i-1])
//            up=down+1;
//        else if(nums[i]<nums[i-1])
//            down=up+1;
//    }
//    return max(up,down);
//}

int main(int argc, const char * argv[]) {
    int a[]={0,0};
    vector<int> nums(a,a+2);
    cout<<wiggleMaxLength(nums)<<endl;
    return 0;
}


