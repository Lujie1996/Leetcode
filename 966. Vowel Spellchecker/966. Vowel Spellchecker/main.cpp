//
//  main.cpp
//  966. Vowel Spellchecker
//
//  Created by Jie Lu on 2019/1/3.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>

string wordToLower(string& word) {
    string res = "";
    for (auto c : word) {
        res += tolower(c);
    }
    return res;
}

string vowelToStar(string& word) {
    unordered_set<char> vowels{'a','e','i','o','u'};
    string res = "";
    for (auto c : word) {
        if (vowels.find(c) != vowels.end()) {
            res += '*';
        }
        else {
            res += c;
        }
    }
    return res;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> words;
    unordered_map<string, string> lowWords, vowelWords;
    
    for (auto word : wordlist) {
        words.insert(word);
        
        string key = wordToLower(word);
        if (lowWords.find(key) == lowWords.end()) {
            lowWords[key] = word;
        }
        
        key = vowelToStar(key);
        if (vowelWords.find(key) == vowelWords.end()) {
            vowelWords[key] = word;
        }
    }
    
    vector<string> res;
    for (auto q : queries) {
        if (words.find(q) != words.end()) {
            res.push_back(q);
        }
        else {
            string lowerQ = wordToLower(q);
            if (lowWords.find(lowerQ) != lowWords.end()) {
                res.push_back(lowWords[lowerQ]);
            }
            else {
                string t = vowelToStar(lowerQ);
                if (vowelWords.find(t) != vowelWords.end()) {
                    res.push_back(vowelWords[t]);
                }
                else {
                    res.push_back("");
                }
            }
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
