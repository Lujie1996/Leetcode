//
//  main.cpp
//  819. Most Common Word
//
//  Created by Jie Lu on 2018/7/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    unordered_map<string, int> wordCount;
    unordered_set<string> bannedSet(banned.begin(), banned.end());
    int i = 0, j = 0, n = (int)paragraph.size();
    while (i < n) {
        while (i < n && (paragraph[i] < 'a' || paragraph[i] >'z')) {
            i++;
        }
        if (i == n) {
            break;
        }
        j = i;
        while (j < n && paragraph[j] >= 'a' && paragraph[j] <= 'z') {
            j++;
        }
        string t = paragraph.substr(i, j - i);
        if (bannedSet.find(t) == bannedSet.end()) {
            wordCount[t] += 1;
        }
        i = j;
    }
    string res;
    int maxCount = 0;
    for (auto x : wordCount) {
        if (x.second > maxCount) {
            maxCount = x.second;
            res = x.first;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    string paragraph = "a.";
    vector<string> banned{"hit"};
    cout<<mostCommonWord(paragraph, banned)<<endl;;
    return 0;
}
