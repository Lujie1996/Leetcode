//
//  main.cpp
//  354. Russian Doll Envelopes
//
//  Created by Jie Lu on 2018/9/29.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// O(n^2) DP
//int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//    int n = (int)envelopes.size();
//    if (n == 0) {
//        return 0;
//    }
//
//    sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//        return a.first < b.first || (a.first == b.first && a.second < b.second);
//    });
//
//    int res = 1;
//    vector<int> dp(n, 1);
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
//                dp[i] = max(dp[i], dp[j]+1);
//            }
//        }
//        res = max(res, dp[i]);
//    }
//    return res;
//}

// O(nlgn) DP
/*
 Actually this idea is more like Greedy.
 We sort envelopes by width in ascending order, and if same width we sort by height in descending order.
 Say envelopes{{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}}, after sort it would be:
 {{1,3},{3,5},{6,8},{6,7},{8,4},{9,5}}
 类似LC200 Longest Increasing Subsequence，因为width已经排序过了，所以不会影响。找到最长递增的height就是所求的答案。
 维护一个dp数组，存储可以装起来的信封的height。遍历排序后的envelopes，当前遍历的记为cur，在dp找height大于等于它的项，找到就替换它。
 由于envelopes事先排序过，cur的width一定大于它所代替的dp中的项，所以能始终保持dp中的信封不会冲突。
 */
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    int n = (int)envelopes.size();
    
    if (n == 0)
        return 0;
    
    sort(envelopes.begin(), envelopes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });
    // pay attention to the difference with O(n^2) solution
    
    vector<int> dp;
    dp.push_back(envelopes[0].second);
    
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
        if (it != dp.end())
            *it = envelopes[i].second;
        else
            dp.push_back(envelopes[i].second);
    }
    
    return (int)dp.size();
}

int main(int argc, const char * argv[]) {
//    vector<pair<int, int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
//    vector<pair<int, int>> envelopes{{4,5},{4,6},{6,7},{2,3},{1,1}};
//    vector<pair<int, int>> envelopes{{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    vector<pair<int, int>> envelopes{{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
//    vector<pair<int, int>> envelopes{{46,89},{50,53},{52,68},{72,45},{77,81}};
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}
