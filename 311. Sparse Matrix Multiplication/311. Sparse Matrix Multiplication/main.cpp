//
//  main.cpp
//  311. Sparse Matrix Multiplication
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int mA = A.size(), nA = A[0].size(), mB = B.size(), nB = B[0].size();
    vector<vector<int>> C(mA, vector<int>(nB, 0));
    
    // a,b * b,c = a,c
    for (int i = 0; i < mA; i++) {
        for (int j = 0; j < nA; j++) {
            if (A[i][j] != 0) {
                for (int k = 0; k < nB; k++) {
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        }
    }
    
    return C;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
