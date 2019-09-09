//
//  main.cpp
//  969. Pancake Sorting
//
//  Created by Jie Lu on 2019/1/15.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void sortUntil(vector<int>& A, vector<int>& res, int pos) {
    if (pos == 0) {
        return;
    }
    int indexOfMaxNum = 0, maxNum = A[0];
    for (int i = 0; i <= pos; i++) {
        if (A[i] > maxNum) {
            maxNum = A[i];
            indexOfMaxNum = i;
        }
    }
    res.push_back(indexOfMaxNum+1);
    res.push_back(pos+1);
    reverse(A.begin(), A.begin()+indexOfMaxNum+1);
    reverse(A.begin(), A.begin()+pos+1);
    sortUntil(A, res, pos-1);
}

vector<int> pancakeSort(vector<int>& A) {
    vector<int> res;
    sortUntil(A, res, A.size() - 1);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> A{3,2,4,1};
    vector<int> res = pancakeSort(A);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
