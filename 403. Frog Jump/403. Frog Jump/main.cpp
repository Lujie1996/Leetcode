//
//  main.cpp
//  403. Frog Jump
//
//  Created by Jie Lu on 2019/2/18.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool canCross(vector<int>& stones) {
    int n = stones.size();
    if (n == 0 || n == 1)
        return true;
    if (n == 2)
        return stones[1] == 1;
    
    unordered_map<int, unordered_set<int>> dp;
    for (auto stone : stones) {
        dp[stone] = unordered_set<int>();
    }
    dp[1].insert(1);
    
    vector<int> bias{-1,0,1};
    for (auto stone : stones) {
        for (auto step : dp[stone]) {
            for (auto t : bias) {
                int nextStep = step + t;
                if (nextStep > 0 && dp.find(stone+nextStep) != dp.end()) {
                    dp[stone+nextStep].insert(nextStep);
                }
            }
        }
    }
//    for (auto row : dp) {
//        cout<<row.first<<": ";
//        for (auto step : row.second) {
//            cout<<step<<" ";
//        }
//        cout<<endl;
//    }
    return dp[stones.back()].size() != 0;
}

int main(int argc, const char * argv[]) {
    vector<int> stones{0,1,3,4,5,7,9,10,12};
    cout<<canCross(stones)<<endl;
    return 0;
}
