//
//  main.cpp
//  373. Find K Pairs with Smallest Sums
//
//  Created by Jie Lu on 2019/2/10.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int i = 0, j = 0;
    vector<pair<int,int>> res;
    if (nums1.size() == 0 || nums2.size() == 0) {
        return res;
    }
    
    int maxCount = min(k, (int)(nums1.size() * nums2.size()));
    while (res.size() < maxCount) {
        res.push_back({nums1[i], nums2[j]});
        
        if (i + 1 < nums1.size() && j + 1 < nums2.size()) {
            if (nums1[i+1] + nums2[j] <= nums1[i] + nums2[j+1]) {
                i++;
            }
            else {
                j++;
            }
        }
        else {
            if (i == nums1.size() && j == nums2.size()) {
                break;
            }
            if (i == nums1.size() - 1) {
                if (nums1[i] + nums1[j] <= nums1[0] + nums2[j+1]) {
                    i = 0;
                    j++;
                }
                else {
                    j++;
                }
            }
            else {
                if (nums1[i] + nums1[j] <= nums1[i+1] + nums2[0]) {
                    j = 0;
                    i++;
                }
                else {
                    i++;
                }
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1{1,1,2}, nums2{1,2,3};
    vector<pair<int, int>> res = kSmallestPairs(nums1, nums2, 10);
    for (auto a : res) {
        cout<<a.first<<" "<<a.second<<endl;
    }
    // [[1,1],[1,1],[2,1],[1,2],[1,2],[2,2],[1,3],[1,3],[2,3]]
    return 0;
}
