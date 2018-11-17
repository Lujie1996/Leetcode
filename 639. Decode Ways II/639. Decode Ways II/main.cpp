//
//  main.cpp
//  639. Decode Ways II
//
//  Created by Jie Lu on 2018/11/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s) {
    int M = 1000000007;
    
    if (s.size() == 0 || s[0] == '0') {
        return 0;
    }
    
    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        if (s[i-1] == '*') {
            dp[i] = dp[i-1] * 9;
            if (s[i-2] == '1') {
                dp[i] = (dp[i] + dp[i-2] * 9) % M;
            }
            else if (s[i-2] == '2') {
                dp[i] = (dp[i] + dp[i-2] * 6) % M;
            }
            else if (s[i-2] == '*'){
                dp[i] = (dp[i] + dp[i-2] * 15) % M;
            }
        }
        else {
            if (s[i-1] == '0') {
                if (i > 1 && (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6')) {
                    dp[i] = dp[i-2];
                }
                else if (i > 1 && s[i-2] == '*'){
                    dp[i] = dp[i-2] * 2;
                }
                else {
                    dp[i] = 0;
                }
            }
            else {
                dp[i] = dp[i-1];
                if (i > 1 && s[i-2] == '*') {
                    if (dp[i-1] <= '6') {
                        dp[i] = (dp[i] + dp[i-2] * 2) % M;
                    }
                    else {
                        dp[i] = (dp[i] + dp[i-2]) % M;
                    }
                }
                else if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6') {
                    dp[i] = (dp[i] + dp[i-2]) % M;
                }
            }
        }
    }
    return dp.back();
}

int main(int argc, const char * argv[]) {
    cout<<numDecodings("**1**")<<endl;
    return 0;
}
