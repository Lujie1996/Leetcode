//
//  main.cpp
//  852. Peak Index in a Mountain Array
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
    int low = 0, high = A.size() - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (mid == low) {
            break;
        }
        if (A[mid] > A[mid-1]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return A[low] > A[low-1] ? low : low-1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
