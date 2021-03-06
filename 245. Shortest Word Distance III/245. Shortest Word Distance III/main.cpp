//
//  main.cpp
//  245. Shortest Word Distance III
//
//  Created by Jie Lu on 2018/6/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    vector<int> index1, index2;
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word1) {
            index1.push_back(i);
        }
        else if (words[i] == word2) {
            index2.push_back(i);
        }
    }
    int i = 0, j = 0, dist = INT_MAX;
    if (word1 == word2) {
        while (i < index1.size() - 1) {
            dist = min(dist, index1[i+1] - index1[i]);
            i++;
        }
    }
    else {
        while (i < index1.size() && j < index2.size()) {
            if (index1[i] < index2[j]) {
                dist = min(dist, index2[j] - index1[i]);
                i++;
            }
            else {
                dist = min(dist, index1[i] - index2[j]);
                j++;
            }
        }
    }
    return dist;
}
int main(int argc, const char * argv[]) {
    vector<string> words{"practice", "makes", "perfect", "coding", "makes"};
    cout<<shortestWordDistance(words, "makes", "makes")<<endl;
    return 0;
}
