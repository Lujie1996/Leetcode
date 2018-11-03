//
//  main.cpp
//  676. Implement Magic Dictionary
//
//  Created by Jie Lu on 2018/11/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

// Very intuitive idea.
//class MagicDictionary {
//private:
//    unordered_set<string> dict;
//public:
//    /** Initialize your data structure here. */
//    MagicDictionary() {
//
//    }
//
//    /** Build a dictionary through a list of words */
//    void buildDict(vector<string> dict) {
//        for (auto s : dict) {
//            this->dict.insert(s);
//        }
//    }
//
//    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
//    bool search(string word) {
//        for (int i = 0; i < word.size(); i++) {
//            for (int j = 0; j < 26; j++) {
//                string newWord = word;
//                newWord[i] = 'a' + j;
//                if (newWord == word) {
//                    continue;
//                }
//                if (dict.find(newWord) != dict.end()) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};

// Instead of just simply store words in dict, now store pattern in dict
// Comparison based on pattern, so for a search key "WORD", now we don't need
// to lookup in dict for 26*4 times, but only 4 times, that is:
// *ORD, W*RD, WO*D, WOR*
class MagicDictionary {
private:
    unordered_map<string, unordered_set<char>> dict;
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto s : dict) {
            for (int i = 0; i < s.size(); i++) {
                string pattern = s.substr(0,i) + "*" + s.substr(i+1);
                this->dict[pattern].insert(s[i]);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            string pattern = word.substr(0,i) + "*" + word.substr(i+1);
            if (dict.find(pattern) != dict.end() && (dict[pattern].size() == 1 && dict[pattern].find(word[i]) == dict[pattern].end() || dict[pattern].size() > 1)) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
