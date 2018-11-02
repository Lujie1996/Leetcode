//
//  main.cpp
//  347. Top K Frequent Elements
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// This is my original solution. Beats 91%.
// First use map to record frequency, then use a vector<pair<int,int>> to store the map.
// Sort the vector and get the first k pairs.
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> numFreq;
    for (auto num : nums) {
        numFreq[num] += 1;
    }
    vector<pair<int, int>> freq(numFreq.begin(), numFreq.end());
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.second > b.second;});
    vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(freq[i].first);
    }
    return res;
}

// Another solution from internet.
// Use map first, then use a maxHeap to find the frequency F of the kth most frequent number.
// Finally iterate the map and store all numbers whose frequency >= F.
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int, int> counts;
//    priority_queue<int, vector<int>, greater<int>> max_k;
//    for(auto i : nums)
//        ++counts[i];
//    for(auto & i : counts) {
//        max_k.push(i.second);
//        // Size of the min heap is maintained at equal to or below k
//        while(max_k.size() > k)
//            max_k.pop();
//    }
//    vector<int> res;
//    for(auto & i : counts) {
//        if(i.second >= max_k.top())
//            res.push_back(i.first);
//    }
//    return res;
//}

// Another solution from internet.
// The fastest among all the three solution, but also needs the most space.
// Use map first, then use many buckets to store all numbers whose frequency == bucket index.
//vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int, int> m;
//    for (int num : nums)
//        ++m[num];
//    vector<vector<int>> buckets(nums.size() + 1);
//    for (auto p : m)
//        buckets[p.second].push_back(p.first);
//    vector<int> ans;
//    for (int i = (int)buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
//        for (int num : buckets[i]) {
//            ans.push_back(num);
//            if (ans.size() == k)
//                break;
//        }
//    }
//    return ans;
//}
int main(int argc, const char * argv[]) {
    vector<int> nums{1,1,1,2,2,3};
    vector<int> res = topKFrequent(nums, 2);
    for (int num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
