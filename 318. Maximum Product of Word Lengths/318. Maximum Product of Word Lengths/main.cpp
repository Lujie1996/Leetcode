//
//  main.cpp
//  318. Maximum Product of Word Lengths
//
//  Created by Jie Lu on 2018/7/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int toWordBit(string word) {
    int res = 0, mask = 1;
    for (int i = 0; i < word.size(); i++) {
        mask = 1;
        for (int j = 0; j < word[i] - 'a'; j++) {
            mask *= 2;
        }
        res |= mask;
    }
    return res;
}
int maxProduct(vector<string>& words) {
    int n = (int)words.size();
    sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {return a.size() < b.size();});
    vector<int> wordBit;
    for (auto word : words) {
        wordBit.push_back(toWordBit(word));
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if ((wordBit[i] & wordBit[j]) == 0) {
                res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> words{"abcw","baz","foo","bar","xtfn","abcdef"};
    cout<<maxProduct(words)<<endl;
    return 0;
}
