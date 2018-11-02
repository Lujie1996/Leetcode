//
//  main.cpp
//  846. Hand of Straights
//
//  Created by Jie Lu on 2018/10/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> numCount;
    for (auto num : hand) {
        numCount[num] += 1;
    }
    while (numCount.size() != 0) {
        auto it = numCount.begin();
        int start = it->first;
        for (int i = 0; i < W; i++) {
            if (numCount.find(start) == numCount.end()) {
                return false;
            }
            if (--numCount[start] == 0) {
                numCount.erase(start);
            }
            start++;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    vector<int> hand{1};
    cout<<isNStraightHand(hand, 1)<<endl;
    return 0;
}
