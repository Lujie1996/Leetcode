//
//  main.cpp
//  821. Shortest Distance to a Character
//
//  Created by Jie Lu on 2018/10/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void walkToEnd(string S, vector<int>& res, char C, int j, int bias) {
    int count = 1;
    while (j >= 0 && j < S.size() && S[j] != C) {
        if (res[j] > count) {
            res[j] = count;
            count++;
            j += bias;
        }
        else {
            break;
        }
    }

}

vector<int> shortestToChar(string S, char C) {
    vector<int> res(S.size(), (int)S.size());
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == C) {
            res[i] = 0;
            walkToEnd(S, res, C, i-1, -1);
            walkToEnd(S, res, C, i+1, 1);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    string S = "loveleetcode";
    char C = 'e';
    vector<int> res = shortestToChar(S, C);
    for (auto c : res) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}
