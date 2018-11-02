//
//  main.cpp
//  438. Find All Anagrams in a String
//
//  Created by Jie Lu on 2018/9/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// sliding window
//vector<int> findAnagrams(string s, string p) {
//    if (s.empty())
//        return {};
//
//    vector<int> res, m(256, 0);
//    int left = 0, right = 0, cnt = (int)p.size(), n = (int)s.size();
//    for (char c : p)
//        m[c]++;
//
//    while (right < n) {
//        if (m[s[right++]]-- >= 1)
//            cnt--;
//        if (cnt == 0)
//            res.push_back(left);
//        if (right - left == p.size() && m[s[left++]]++ >= 0)
//            cnt++;
//    }
//    return res;
//}

vector<int> findAnagrams(string s, string p) {
    vector<int> pv(256,0), sv(256,0), res;
    // pv is map(counter of letters) for string p, and sv is map for string s
    if(s.size() < p.size())
        return res;
    for(int i = 0; i < p.size(); ++i)
    {
        ++pv[p[i]];
        ++sv[s[i]];
    }
    if(pv == sv)
        res.push_back(0);
    for(int i = (int)p.size(); i < (int)s.size(); ++i)
    {
        ++sv[s[i]];
        --sv[s[i-p.size()]];
        if(pv == sv)
            res.push_back(i-(int)p.size()+1);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "abcab";
    string p = "ab";
    vector<int> res = findAnagrams(s, p);
    for (auto pos : res) {
        cout<<pos<<" ";
    }
    cout<<endl;
    return 0;
}
