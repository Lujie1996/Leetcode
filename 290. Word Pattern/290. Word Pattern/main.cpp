//
//  main.cpp
//  290. Word Pattern
//
//  Created by Jie Lu on 2018/5/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

// My original solution, beat 100% submissions.
bool wordPattern(string pattern, string str) {
    unordered_map<char, string> charToStr;
    unordered_map<string, char> strToChar;
    int indexOfStr = 0, lenStr = (int)str.length();
    int i = 0;
    for (; i < pattern.length() && indexOfStr < lenStr; i++) {
        string word = "";
        while (indexOfStr < lenStr && str[indexOfStr] != ' ') {
            word += str[indexOfStr++];
        }
        indexOfStr++;
        char c = pattern[i];
        if (charToStr.find(c) == charToStr.end()) {
            charToStr[c] = word;
            if (strToChar.find(word) == strToChar.end()) {
                strToChar[word] = c;
            }
            else {
                return false;
            }
        }
        else {
            if (charToStr[c] != word) {
                return false;
            }
        }
    }
    return indexOfStr > lenStr &&  i == pattern.length() ? true : false;
}

// Another solution from internet, which is more concise.
// Map char and word to a certain integer instead of map char to word (and word to char)
// Similar idea can be found in LC205 Isomorphic Strings
//bool wordPattern(string pattern, string str) {
//    map<char, int> p2i;
//    map<string, int> w2i;
//    istringstream in(str);
//    int i = 0, n = pattern.size();
//    for (string word; in >> word; ++i) {
//        if (i == n || p2i[pattern[i]] != w2i[word])
//            return false;
//        p2i[pattern[i]] = w2i[word] = i + 1; // not i. Map key 0 is left for any char and word that is not currently mapped.
//    }
//    return i == n;
//}
int main(int argc, const char * argv[]) {
    if (wordPattern("he", "unit")) {
        cout<<"TRUE"<<endl;
    }
    else {
        cout<<"FALSE"<<endl;
    }
    return 0;
}
