//
//  main.cpp
//  278. First Bad Version
//
//  Created by Jie Lu on 2018/5/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int a[] = {1,2,3,4,5,6,7,8,9};
vector<int> versions(a, a+9);
int firstBadVersionNo = 2;

bool isBadVersion(int version) {
    if (version >= firstBadVersionNo) {
        return true;
    }
    return false;
}
int firstBadVersion(int n) {
    if (!isBadVersion(n)) {
        return 0;
    }
    int left = 1, right = n, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}
int main(int argc, const char * argv[]) {
    cout<<firstBadVersion(2)<<endl;
    return 0;
}
