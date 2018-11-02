//
//  main.cpp
//  763. Partition Labels
//
//  Created by Jie Lu on 2018/8/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// This is my original solution. Pretty the same with Merge Intervals
// First, get an array of pair<int,int> which stands for the indices of the left and right bound of each alphabet (call it 'alphaRange');
// Second, sort this array to ascending order according to the alphsRange's 'first', that is the index that the alphabet first appeared;
// Third, use the Merge Interval idea to divide the alphaRanges into groups so that none of which overlaps with other alphaRange.
vector<int> partitionLabels(string S) {
    vector<int> res;
    unordered_map<char, pair<int, int>> alphaIndices;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        if (alphaIndices.find(c) == alphaIndices.end()) {
            alphaIndices[c].first = i;
            alphaIndices[c].second = i;
        }
        else {
            alphaIndices[c].second = i;
        }
    }
    vector<pair<int, int>> bound;
    for (auto t : alphaIndices) {
        bound.push_back(make_pair(t.second.first, t.second.second));
    }
    sort(bound.begin(), bound.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {return a.first < b.first;});
    int left = 0, right = 0, i = 0;
    while (i < bound.size()) {
        left = bound[i].first;
        right = bound[i].second;
        while (++i < bound.size() && bound[i].first < right) {
            if (bound[i].second > right) {
                right = bound[i].second;
            }
        }
        res.push_back(right - left + 1);
    }
    return res;
}

// From discuss. The idea is the same, but this one has more concise implementation.
//vector<int> partitionLabels(string S) {
//    vector<int> last(26, 0); // only need to record the last place an alphabet appears.
//    for (int i = 0; i < S.length(); i++) {
//        last[S[i]-'a'] = i;
//    }
//    int start, end;
//    start = end = 0;
//    vector<int> ans;
//    for (int i = 0; i < S.length(); i++) {
//        end = max(end, last[S[i]-'a']);
//        if (i == end) { // if current position is the end of current range, then we get one unoverlapped range.
//            ans.push_back(i - start + 1);
//            start = i + 1;
//        }
//    }
//    return ans;
//}

int main(int argc, const char * argv[]) {
    vector<int> res = partitionLabels("eaaaabaaec");
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
