//
//  main.cpp
//  208. Implement Trie (Prefix Tree)
//
//  Created by Jie Lu on 2018/7/25.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> alphabets;
    TrieNode() {
        isWord = false;
        alphabets.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                TrieNode* thisChar = new TrieNode();
                p->alphabets[index] = thisChar;
                p = thisChar;
            }
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                return false;
            }
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (p->alphabets[index] != NULL) {
                p = p->alphabets[index];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main(int argc, const char * argv[]) {
    Trie* obj = new Trie();
    obj->insert("apple");
    if (obj->search("apple")) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
    if (obj->startsWith("ape")) {
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }
    return 0;
}
