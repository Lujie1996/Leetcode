//
//  main.cpp
//  159. Longest Substring with At Most Two Distinct Characters
//
//  Created by Jie Lu on 2018/9/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> charCount;
    int i = 0, j = 0, maxLen = 0;
    while (j < s.size()) {
        char c = s[j];
        if (charCount.find(c) != charCount.end() || charCount.size() < 2) {
            charCount[c] += 1;
            j++;
            continue;
        }
        else {
            maxLen = max(maxLen, j - i);
            charCount[c] = 1;
            j++;
            while (charCount.size() > 2) {
                charCount[s[i]] -= 1;
                if (charCount[s[i]] == 0) {
                    charCount.erase(s[i]);
                }
                i++;
            }
        }
    }
    
    return max(maxLen, j-i);
}

int main(int argc, const char * argv[]) {
    cout<<lengthOfLongestSubstringTwoDistinct("ababcbcbaaabbdef")<<endl;
    return 0;
}
