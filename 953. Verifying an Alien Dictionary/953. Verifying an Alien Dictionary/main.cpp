//
//  main.cpp
//  953. Verifying an Alien Dictionary
//
//  Created by Jie Lu on 2019/8/19.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool inOrder(string& a, string& b, int rank[]) {
    int i = 0;
    while (i < a.size() && i < b.size()) {
        if (rank[a[i]-'a'] == rank[b[i]-'a']) {
            i++;
        }
        else {
            return rank[a[i]-'a'] < rank[b[i]-'a'];
        }
    }
    return a.size() <= b.size();
}

bool isAlienSorted(vector<string>& words, string order) {
    int rank[26] = {0};
    for (int i = 0; i < order.size(); i++) {
        rank[order[i]-'a'] = i;
    }
    
    for (int i = 1; i < words.size(); i++) {
        if (!inOrder(words[i-1], words[i], rank)) {
            return false;
        }
    }
    return true;
}



int main(int argc, const char * argv[]) {
    vector<string> words = {"hello", "leetcode"};
    cout<<isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz")<<endl;
    
    return 0;
}
