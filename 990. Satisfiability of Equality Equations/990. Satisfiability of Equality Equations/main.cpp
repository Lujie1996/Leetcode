//
//  main.cpp
//  990. Satisfiability of Equality Equations
//
//  Created by Jie Lu on 2019/2/12.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> root;

bool equationsPossible(vector<string>& equations) {
    root.resize(26);
    for (int i = 0; i < 26; i++) {
        root[i] = i;
    }
    for (auto e : equations) {
        if (e[1] == '=') {
            root[find(e[0]-'a')] = find(e[3]-'a');
        }
    }
    for (auto e : equations) {
        if (e[1] == '!' && find(e[0]-'a') == find(e[3]-'a')) {
            return false;
        }
    }
    return true;
}

int find(int node) {
    while (root[node] != node) {
        node = root[node];
    }
    return node;
}

int main(int argc, const char * argv[]) {
    vector<string> es{"a==b","b!=a"};
    cout<<equationsPossible(es)<<endl;
    return 0;
}
