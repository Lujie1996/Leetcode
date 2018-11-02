//
//  main.cpp
//  760. Find Anagram Mappings
//
//  Created by Jie Lu on 2018/6/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < B.size(); i++) {
        indexMap[B[i]] = i;
    }
    vector<int> res(A.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        res[i] = indexMap[A[i]];
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<int> a{12, 28, 46, 32, 50}, b{50, 12, 32, 46, 28};
    vector<int> res = anagramMappings(a, b);
    for (auto num : res) {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
