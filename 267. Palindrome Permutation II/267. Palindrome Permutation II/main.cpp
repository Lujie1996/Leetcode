//
//  main.cpp
//  267. Palindrome Permutation II
//
//  Created by Jie Lu on 2018/6/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 1. Obtain a map 'evenCounter', its key is char that appear even number of times in string, its value is the exact number of times it appears;
// 2. Use a int variable 'oddChar' to store the char that appears odd number of times;
// 3. Add {oddChar,count[oddChar]-1} to 'evenCounter';
// 4. Iteratively get all permutations using evenCounter;
void getPalindrome(vector<string>& res, unordered_map<int, int>& evenCounter, string& cur, int pos) {
    if (pos >= cur.size() / 2) {
        res.push_back(cur);
        return;
    }
    for (auto& evenChar : evenCounter) {
        if (evenChar.second != 0) {
            evenChar.second -= 2;
            char c = evenChar.first;
            cur[pos] = c;
            cur[cur.size() - pos - 1] = c;
            getPalindrome(res, evenCounter, cur, pos + 1);
            evenChar.second += 2;
        }
    }
}
vector<string> generatePalindromes(string s) {
    vector<string> res;
    int count[256] = {0};
    for (auto c : s) {
        count[c] += 1;
    }
    int oddChar = -1; // char that appears odd number of times in string.
    unordered_map<int, int> evenCounter; // chars that appear even number of times in string.
    for (int i = 0; i < 256; i++) {
        if (count[i]) {
            if (count[i] % 2 == 0) {
                evenCounter[i] = count[i];
            }
            else {
                if (oddChar == -1) {
                    oddChar = i;
                }
                else {
                    // there is already an oddChar, and there can't be two oddChar
                    return res;
                }
            }
        }
    }
    for (auto a : evenCounter) {
        cout<<a.first<<": "<<a.second<<endl;
    }
    string cur(s.size(), 0);
    if (oddChar != -1) {
        cur[s.size() / 2] = oddChar;
    }
    getPalindrome(res, evenCounter, cur, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = generatePalindromes("aabbccc");
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
