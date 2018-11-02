//
//  main.cpp
//  30. Substring with Concatenation of All Words
//
//  Created by Jie Lu on 2018/5/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// This solutin is my original idea, which is very intuitive. It takes around 320ms to go through all test cases.
//vector<int> findSubstring(string s, vector<string>& words) {
//    vector<int> res;
//    if (s.length() == 0 || words.size() == 0)
//        return res;
//    unordered_map<string, int> wordSet;
//    for (string word : words) {
//        wordSet[word] += 1;
//    }
//    int wordLen = (int)words[0].length(), wordNum = (int)words.size();
//    int windowLen = wordLen * wordNum;
//    for (int i = 0; i + windowLen <= (int)s.length(); i++) {
//        // s.substr(i, windowLen)
//        // The main ides of this problem is to try every possible substr whose length is windowLen
//        if (i == 8) {
//
//        }
//        unordered_map<string, int> included(wordSet);
//        int j;
//        for (j = 0; j + wordLen <= windowLen; j += wordLen) {
//            string thisWord = s.substr(i+j, wordLen);
//            if (included.find(thisWord) == included.end() || included[thisWord] == 0) {
//                break;
//            }
//            else {
//                included[thisWord] -= 1;
//            }
//        }
//        if (j == windowLen) {
//            res.push_back(i);
//        }
//    }
//    return res;
//}

// This is not mhy original idea. This is actually smarter, and it takes only around 25ms to pass all test cases.
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (s.length() <= 0 || words.size() <= 0 || words[0].length() <= 0)
        return ans;
    
    const int str_len = (int)s.length();
    const int word_num = (int)words.size();
    const int word_len = (int)words[0].length();
    unordered_map<string, int> word_count;
    for (string& word : words)
        ++word_count[word];
    
    for (int offset = 0; offset < word_len; ++offset) {
        // This for loop is critical. The first iteration tries words at index [0 + k * word_len], next iteration tries words at index [1 + k * word_len]
        int num = 0; // number of target words in substring
        unordered_map<string, int> count;
        string candidate;
        int idx = offset; // start index of substring
        for (int i = offset; i <= str_len - word_len; i += word_len) {
            candidate = s.substr(i, word_len);
            if (word_count.find(candidate) != word_count.end()) {
                ++count[candidate];
                ++num;
                while (count[candidate] > word_count[candidate]) {
                    // Here adopts the ides from 'Longest Substring Without Repeating Characters'
                    // Keep removing the beginning word in substring until the count of ending word does not exceeds its count in given word_count
                    --count[s.substr(idx, word_len)];
                    --num;
                    idx += word_len;
                }
                if (num == word_num)
                    ans.push_back(idx);
            }
            else {
                num = 0;
                count.clear();
                idx = i + word_len;
            }
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    string s = "wordgoodgoodgoodbestword";
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("good");
    words.push_back("best");
    vector<int> res = findSubstring(s, words);
    for (int num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
