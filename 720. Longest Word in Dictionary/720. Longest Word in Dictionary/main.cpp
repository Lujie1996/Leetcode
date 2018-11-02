//
//  main.cpp
//  720. Longest Word in Dictionary
//
//  Created by Jie Lu on 2018/7/25.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char c;
    bool isWord;
    vector<TrieNode*> alphabets;
    TrieNode() {
        c = 0;
        isWord = false;
        alphabets.resize(26, NULL);
    }
    TrieNode(char thisChar) {
        c = thisChar;
        isWord = false;
        alphabets.resize(26, NULL);
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                TrieNode* thisChar = new TrieNode(word[i]);
                p->alphabets[index] = thisChar;
                p = thisChar;
            }
        }
        p->isWord = true;
    }
    int dfsTrie(TrieNode* root, string &word) {
        if (root == NULL) {
            return 0;
        }
        if (!root->isWord) {
            return -1;
        }
        int maxLen = 0;
        string maxWord;
        for (int i = 0; i < 26; i++) {
            if (root->alphabets[i] != NULL) {
                string thisWord;
                int thisWordLen = dfsTrie(root->alphabets[i], thisWord);
                if (thisWordLen > maxLen) {
                    maxLen = thisWordLen;
                    maxWord = thisWord;
                }
            }
        }
        word = root->c + maxWord;
        return (int)word.size();
    }
    string findLongestWord() {
        root->isWord = true;
        string word;
        dfsTrie(root, word);
        return word.substr(1);
    }
};

string longestWord(vector<string>& words) {
    Trie* trie = new Trie();
    for (auto word : words) {
        trie->insert(word);
    }
    string res = trie->findLongestWord();
    delete trie;
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> words{"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"};
//    vector<string> words{"a","ab","bde"};
//    vector<string> words{"w","wo","wor","worl","world"};
    cout<<longestWord(words)<<endl;
    return 0;
}
