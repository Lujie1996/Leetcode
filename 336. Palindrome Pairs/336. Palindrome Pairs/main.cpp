//
//  main.cpp
//  336. Palindrome Pairs
//
//  Created by Jie Lu on 2018/7/26.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// Brute Force solution, TLE at 115/134 test case.
//bool isPalindrome(string& a, string& b) {
//    string concatenated = a + b;
//    int i = 0, j = (int)concatenated.size() - 1;
//    while (i < j) {
//        if (concatenated[i] == concatenated[j]) {
//            i++;
//            j--;
//        }
//        else {
//            return false;
//        }
//    }
//    return true;
//}
//vector<vector<int>> palindromePairs(vector<string>& words) {
//    vector<vector<int>> res;
//    for (int i = 0; i < words.size(); i++) {
//        for (int j = 0; j < words.size(); j++) {
//            if (i == j) {
//                continue;
//            }
//            if (isPalindrome(words[i], words[j])) {
//                vector<int> pair{i,j};
//                res.push_back(pair);
//            }
//        }
//    }
//    return res;
//}

// hash solution. beats 50%
vector<vector<int>> palindromePairs2(vector<string>& words) {
    unordered_map<string, int> dict;
    vector<vector<int>> ans;
    // build dictionary
    for(int i = 0; i < words.size(); i++) {
        string key = words[i];
        reverse(key.begin(), key.end());
        dict[key] = i;
    }
    // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
    if(dict.find("")!=dict.end()){
        for(int i = 0; i < words.size(); i++){
            if(i == dict[""])
                continue;
            if(isPalindrome(words[i]))
                ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
        }
    }
    
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words[i].size(); j++) {
            string left = words[i].substr(0, j);
            string right = words[i].substr(j, words[i].size() - j);
            
            if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
            }
            
            if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                ans.push_back({dict[right], i});
            }
        }
    }
    
    return ans;
}

bool isPalindrome(string str){
    int i = 0;
    int j = str.size() - 1;
    
    while(i < j) {
        if(str[i++] != str[j--]) return false;
    }
    
    return true;
}

// Trie Solution, beats 18% submissions.
class TrieNode {
public:
    char c;
    int wordIndex;
    vector<TrieNode*> alphabets;
    TrieNode() {
        c = 0;
        wordIndex = -1;
        alphabets.resize(26, NULL);
    }
    TrieNode(char thisChar, int index) {
        c = thisChar;
        wordIndex = index;
        alphabets.resize(26, NULL);
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word, int wordIndex) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                TrieNode* thisChar = new TrieNode(word[i], -1);
                p->alphabets[index] = thisChar;
                p = thisChar;
            }
        }
        p->wordIndex = wordIndex;
    }
    int searchAndGetWordIndex(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                return -1;
            }
        }
        return p->wordIndex;
    }
};
bool isPalindrome(string s) {
    if (s.size() == 0) {
        return true;
    }
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (s[i] == s[j]) {
            i++;
            j--;
        }
        else {
            break;
        }
    }
    return i >= j;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
    Trie* trie = new Trie();
    int emptyStringIndex = -1; // corner case: {"a",""}
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (word.size() == 0) {
            emptyStringIndex = i;
        }
        reverse(word.begin(), word.end());
        trie->insert(word, i);
    }
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int n = (int)word.size();
        if (n > 0 && emptyStringIndex > -1 && isPalindrome(word)) {
            vector<int> thisPair{i, emptyStringIndex};
            res.push_back(thisPair);
        }
        for (int j = 1; j <= n; j++) {
            // why starting from j = 1?
            // Since every 'for' iteration, we test candidate strings in both left and right side
            // If not starting from j = 1, every pair will appear twice in result.
            string left = word.substr(0,j), right = word.substr(j);
            int index = trie->searchAndGetWordIndex(left);
            // if candidate string is at right side of word: left right candidate
            if (i != index && index >= 0 && isPalindrome(right)) {
                vector<int> thisPair{i, index};
                res.push_back(thisPair);
            }
            // if candidate string is at left side of word: candidate left right
            index = trie->searchAndGetWordIndex(right);
            if (i != index && index >= 0 && isPalindrome(left)) {
                vector<int> thisPair{index, i};
                res.push_back(thisPair);
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
//    vector<string> words{"abcd","dcba","lls","s","sssll"};
    vector<string> words{"a",""};
    vector<vector<int>> res = palindromePairs(words);
    for (auto pair : res) {
        cout<<pair[0]<<","<<pair[1]<<endl;
    }
    return 0;
}
