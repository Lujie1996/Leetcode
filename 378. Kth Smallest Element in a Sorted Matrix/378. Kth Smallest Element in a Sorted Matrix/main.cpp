//
//  main.cpp
//  378. Kth Smallest Element in a Sorted Matrix
//
//  Created by Jie Lu on 2018/7/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 Simply use heap. O(nlgn) time and O(n) space
 There is a better way using heap but saves a lot of space
 1. Create a min-heap using the elements on the 1st row;
 2. Do this k-1 times:
        Get the top element from heap, obtain its i and j and push matrix[i+1][j] into heap.
        (matrix[i+1][j] is the element right below the previous top element)
 */
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = (int)matrix.size();
    priority_queue<int> heap;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            heap.push(matrix[i][j]);
        }
    }
    int t = n * n - k;
    for (int i = 0; i < t; i++) {
        heap.pop();
    }
    return heap.top();
}
int main(int argc, const char * argv[]) {
    /*
     [ 1,  5,  9, 11],
     [10, 12, 13, 14],
     [12, 13, 15, 28],
     [14, 16, 17, 29]
     
     1,5,9,10,11,12,12,13,13,14,14,15,16,17,28,29
     */
    vector<vector<int>> matrix{{1,5,9,11},{10,12,13,14},{12,13,15,28},{14,16,17,29}};
//    vector<vector<int>> matrix{{1,2},{1,3}};
    cout<<kthSmallest(matrix, 2)<<endl;
    return 0;
}
