//
//  main.cpp
//  418. Sentence Screen Fitting
//
//  Created by Jie Lu on 2018/8/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int count = 0, n = (int)sentence.size();
    vector<int> dp(n, 0);
    // dp[i]: for each line how many words dp[i] can be put when starting with word i.
    for (int i = 0; i < n; i++) {
        int colIndex = 0, chosenWord = i;
        while (colIndex < cols) {
            if (colIndex + sentence[chosenWord % n].size() <= cols) {
                colIndex += sentence[chosenWord % n].size();
            }
            else {
                break;
            }
            colIndex++;
            chosenWord++;
            dp[i]++;
        }
    }
    // count: the number of words that can be put in the whole screen
    for (int i = 0; i < rows; i++) {
        int j = count % n;
        count += dp[j];
    }
    return count / n;
}
int main(int argc, const char * argv[]) {
    vector<string> sentence1{"I", "had", "apple", "pie"};
    vector<string> sentence2{"a", "bcd", "e"};
    vector<string> sentence3{"f", "p", "a"};
    vector<string> sentence4{"hello"};
    cout<<wordsTyping(sentence1, 4, 5)<<endl; // 1
    cout<<wordsTyping(sentence2, 3, 6)<<endl; // 2
    cout<<wordsTyping(sentence3, 8, 7)<<endl;
    cout<<wordsTyping(sentence3, 3, 1)<<endl;
    cout<<wordsTyping(sentence4, 1000, 1)<<endl;
    return 0;
}
