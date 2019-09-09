//
//  main.cpp
//  97. Interleaving String
//
//  Created by Jie Lu on 2018/9/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    
    set<vector<int>> dp{{-1,-1}};
    // dp records all pairs of (i,j) which by interleaving s1[0..i] and s2[0..j] can form s3
    for (int i = 0; i < s3.size(); i++) {
        if (dp.size() == 0) {
            return false;
        }
        set<vector<int>> next;
        // iterate all pairs in dp.
        // for every pair [m,n], see if we can get s3[i] by trying [m+1,n] and [m,n+1]
        for (auto a : dp) {
            int m = a[0], n = a[1];
            if (m + 1 < s1.size() && s1[m+1] == s3[i]) {
                next.insert({m+1, n});
            }
            if (n + 1 < s2.size() && s2[n+1] == s3[i]) {
                next.insert({m, n+1});
            }
        }
        dp = next;
    }
    return dp.size() != 0;
}

int main(int argc, const char * argv[]) {
    /*
     "abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb"
     "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc"
     "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc"
     */
    if (isInterleave("abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb", "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc", "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
