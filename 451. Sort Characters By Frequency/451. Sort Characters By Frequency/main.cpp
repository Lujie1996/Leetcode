//
//  main.cpp
//  451. Sort Characters By Frequency
//
//  Created by Jie Lu on 2018/7/19.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> charCount;
    for (auto c : s) {
        charCount[c] += 1;
    }
    vector<pair<char, int>> charcount(charCount.begin(), charCount.end());
    sort(charcount.begin(), charcount.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {return a.second > b.second;});
    string res;
    for (auto p : charcount) {
        for (int i = 0; i < p.second; i++) {
            res += p.first;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    string s = "Aabb";
    cout<<frequencySort(s)<<endl;
    return 0;
}
