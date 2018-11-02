//
//  main.cpp
//  299. Bulls and Cows
//
//  Created by Jie Lu on 2018/5/12.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

string getHint(string secret, string guess) {
    unordered_map<char, int> charCount;
    int bull = 0, cow = 0;
    for (char c : secret)
        charCount[c] += 1;
    for (int i = 0; i < (int)secret.length(); i++) {
        char c = guess[i];
        if (secret[i] == c) {
            bull++;
            if (charCount[c] == 0) {
                // Consider secret = "1122" and guess = "1222", when scan from left to right and index = 1, '1' in secret and '2' in guess makes cow increase by 1.
                // But in fact the '2' in guess should match with both '2' in secret, so there should be no remaining '2' to secret.
                // Therefore the first '2' in guess is not included in the word set of secret.
                // This if() deals with this problem. If right now its a match(bull) but there is no more charCount(==0), this means somewhere before current position,
                // this char was used to increase cow, so reduce cow by 1.
                cow--;
            }
            else {
                charCount[c] -= 1;
            }
        }
        else {
            if (charCount[guess[i]] > 0) {
                cow++;
                charCount[guess[i]] -= 1;
            }
        }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
}
int main(int argc, const char * argv[]) {
    cout<<getHint("1122", "2211")<<endl; // 0A4B
    cout<<getHint("1122", "1222")<<endl; // 3A0B
    return 0;
}
