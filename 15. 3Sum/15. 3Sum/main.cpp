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

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int N = (int)nums.size();
    
    if (N > 2) {
        int a, b, c, v;
        sort(nums.begin(), nums.end());
        
        for(size_t i = 0; i < N - 2; i++) {
            a = nums[i];
            if (a > 0) {
                break;
            }
            if (i > 0 && a == nums[i - 1]) {
                continue;
            }
            
            for (size_t left = i + 1, right = N - 1; left < right; ) {
                b = nums[left];
                c = nums[right];
                
                v = a + b + c;
                if(v == 0) {
                    result.push_back(vector<int>({a, b, c}));
                    
                    for(left++; left < N - 1 && b == nums[left]; left++);
                    for(right--; right > 0 && c == nums[right]; right--);
                }
                else if (v > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
