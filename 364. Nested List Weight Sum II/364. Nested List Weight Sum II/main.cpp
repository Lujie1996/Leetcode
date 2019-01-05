//
//  main.cpp
//  364. Nested List Weight Sum II
//
//  Created by Jie Lu on 2018/12/28.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

void dfs(vector<NestedInteger>& nestedList, int depth, vector<int>& levels) {
    for (auto ni : nestedList) {
        if (ni.isInteger()) {
            levels[depth] += ni.getInteger();
        }
        else {
            if (levels.size() <= depth + 1) {
                levels.push_back(0);
            }
            dfs(ni.getList(), depth+1, levels);
        }
    }
}
int depthSumInverse(vector<NestedInteger>& nestedList) {
    vector<int> levels{0};
    dfs(nestedList, 0, levels);
    
    int sum = 0, n = levels.size();
    for (int i = n-1; i >= 0; i--) {
        sum += levels[i] * (n - i);
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
