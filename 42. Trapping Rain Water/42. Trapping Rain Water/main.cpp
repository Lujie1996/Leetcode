//
//  main.cpp
//  42. Trapping Rain Water
//
//  Created by Jie Lu on 2018/4/3.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() <= 2) {
        return 0;
    }
    int i, maxHeight, maxHeightIndex;
    maxHeight = maxHeightIndex =  0;
    for (i = 0; i < height.size(); i++) {
        if(height[i] > maxHeight) {
            maxHeightIndex = i;
            maxHeight = height[i];
        }
    }
    int root = height[0], res = 0;
    for (i = 0; i < maxHeightIndex; i++) {
        if (height[i] > root) {
            root = height[i];
        }
        else {
            res += (root - height[i]);
        }
    }
    root = height[height.size() - 1];
    for (i = (int)height.size() - 1; i > maxHeightIndex; i--) {
        if (height[i] > root) {
            root = height[i];
        }
        else {
            res += (root - height[i]);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
//    int nums[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int nums[] = {5,2,1,2,1,5};
    vector<int> height(nums, nums + 6);
    cout<<trap(height)<<endl;
    return 0;
}
