//
//  main.cpp
//  673. Number of Longest Increasing Subsequence
//
//  Created by Jie Lu on 2018/5/24.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// This is actually the question that I was asked when interviewing Toutiao. Didn't solved at that time
// I used another 30min after the interview to solve this, along with countless times of debugging,
// which is not supported in interview terminal. Also this is not a good solution.
int findNumberOfLIS(vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n, 1);
    vector<int> pre(n, 0);
    pre[0] = 1;
    int maxLen = 1; // When n == 1, it won't enter the next for loop, so set maxLen to 1
    for (int i = 1; i < n;i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        for (int j = 0; j < i; j++) {
            if (dp[j] + 1 == dp[i] && nums[j] < nums[i]) {
                pre[i] += pre[j];
            }
        }
        if (pre[i] == 0) {
            // pre[i] == 0 means nums[i] could be the start point of new subsequence
            pre[i] = 1;
        }
        maxLen = max(maxLen, dp[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) {
            res += pre[i];
        }
    }
    return res;
}

// Another solution from dicussion zone. The idea is pretty the same but optimizing in implementation. The code below is very smart:
// if (len[j]+1>len[i]) {//find a longer LIS, reset cnt[i]} else if (len[j]+1==len[i]) {//not a longer LIS, add it to cnt[i]}
// This combines two for loops into one.
//int findNumberOfLIS(vector<int>& nums) {
//    int n = (int)nums.size(), maxlen = 1, ans = 0;
//    vector<int> cnt(n, 1), len(n, 1);
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (nums[i] > nums[j]) {
//                if (len[j] + 1 > len[i]) {
//                    len[i] = len[j] + 1;
//                    cnt[i] = cnt[j];
//                }
//                else if (len[j] + 1 == len[i])
//                    cnt[i] += cnt[j];
//            }
//        }
//        maxlen = max(maxlen, len[i]);
//    }
//    for (int i = 0; i < n; i++)
//        if (len[i] == maxlen)
//            ans += cnt[i];
//    return ans;
//}

int main() {
//    vector<int> nums{1,3,5,4,7};
//    cout<<findNumberOfLIS(nums)<<endl;
//    vector<int> nums2{2,2,2,2,2};
//    cout<<findNumberOfLIS(nums2)<<endl;
//    vector<int> nums3{1,2,4,3,5,4,7,2};
//    cout<<findNumberOfLIS(nums3)<<endl;
    vector<int> nums3{1};
    cout<<findNumberOfLIS(nums3)<<endl;
    return 0;
}
