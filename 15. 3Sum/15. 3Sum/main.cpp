//
//  main.cpp
//  15. 3Sum
//
//  Created by Jie Lu on 2018/9/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//vector<vector<int>> threeSum(vector<int>& nums) {
//    vector<vector<int>> result;
//    int N = (int)nums.size();
//
//    if (N > 2) {
//        int a, b, c, v;
//        sort(nums.begin(), nums.end());
//
//        for(size_t i = 0; i < N - 2; i++) {
//            a = nums[i];
//            if (a > 0) {
//                break;
//            }
//            if (i > 0 && a == nums[i - 1]) {
//                continue;
//            }
//
//            for (size_t left = i + 1, right = N - 1; left < right; ) {
//                b = nums[left];
//                c = nums[right];
//
//                v = a + b + c;
//                if(v == 0) {
//                    result.push_back(vector<int>({a, b, c}));
//
//                    for(left++; left < N - 1 && b == nums[left]; left++);
//                    for(right--; right > 0 && c == nums[right]; right--);
//                }
//                else if (v > 0) {
//                    right--;
//                }
//                else {
//                    left++;
//                }
//            }
//        }
//    }
//
//    return result;
//}

// 2018/11/6
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            break;
        }
        int target = -nums[i];
        
        int low = i + 1, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];
            if (sum == target) {
                vector<int> t{nums[i], nums[low], nums[high]};
                res.push_back(t);
                while (low < high && nums[low] == t[1]) {
                    low++;
                }
                while (low < high && nums[high] == t[2]) {
                    high--;
                }
            }
            else if (sum > target){
                high--;
            }
            else {
                low++;
            }
        }
        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    for (auto a : res) {
        for (auto num : a) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
