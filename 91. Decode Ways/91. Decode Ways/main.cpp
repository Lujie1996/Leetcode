//
//  main.cpp
//  91. Decode Ways
//
//  Created by Jie Lu on 2018/11/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s) {
    if (s.empty() || (s.size() > 1 && s[0] == '0'))
        return 0;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1; // dp[i]: number of decodings of s.substr(0,i)   (not including s[i])
    for (int i = 1; i < dp.size(); ++i) {
        if (s[i - 1] == '0'){
            if (i > 1 && (s[i - 2] == '1' || s[i - 2] == '2')) {
                dp[i] = dp[i - 2];
            }
            else {
                dp[i] = 0;
            }
        }
        else {
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))){
                dp[i] = dp[i - 2] + dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }
        // dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1]; // case 1: s[0:i-2] and s[i-1] no intersection
        // if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
        // case 2: s[i-2] and s[i-1] combines a word
        //     dp[i] += dp[i - 2];
        // }
    }
    return dp.back();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
