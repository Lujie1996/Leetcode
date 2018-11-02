//
//  main.cpp
//  244. Shortest Word Distance II
//
//  Created by Jie Lu on 2018/6/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDistance {
public:
    unordered_map<string, vector<int>> wordIndices;
    
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            wordIndices[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0, dist = INT_MAX;
        vector<int> index1 = wordIndices[word1], index2 = wordIndices[word2];
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
        return dist;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> words{"practice", "makes", "perfect", "coding", "makes"};
    WordDistance obj(words);
    cout<<obj.shortest("practice","coding")<<endl;
    return 0;
}
