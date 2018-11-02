//
//  main.cpp
//  59. Spiral Matrix II
//  两道Spiral Matrix的题目，上一道用到了四个边界变量控制（upLimit，rightLimit等等），后来想了一下可以直接用一个变量loop控制，核心思想其实还是一样的
//  Created by Jie Lu on 2018/4/4.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int step = 1;
    if(n == 0)
        return res;
    int loop = 0, i;
    n -= 1;
    while(n >= loop) {
        for (i = loop; i <= n - loop; i++) {
            res[loop][i] = step;
            step += 1;
        }
        for (i = loop + 1; i <= n - loop; i++) {
            res[i][n - loop] = step;
            step += 1;
        }
        for (i = n - loop - 1; i >= loop; i--) {
            res[n - loop][i] = step;
            step += 1;
        }
        for (i = n - loop - 1; i > loop; i--) {
            res[i][loop] = step;
            step += 1;
        }
        loop += 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int n = 4;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
