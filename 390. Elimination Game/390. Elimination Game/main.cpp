//
//  main.cpp
//  390. Elimination Game
//
//  Created by Jie Lu on 2018/6/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void display(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

// This is my original code. But TLE when n is very big (e.g. 100000000)
int lastRemaining(int n) {
    vector<int> nums(n, 0);
    int cnt = 0;
    while (true) {
        if (cnt == n - 1) {
            break;
        }
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (flag == 0) {
                    flag = 1;
                }
                else {
                    nums[i] = 1;
                    cnt++;
                    flag = 0;
                }
            }
        }
        display(nums);
        if (cnt == n - 1) {
            break;
        }
        flag = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                if (flag == 0) {
                    flag = 1;
                }
                else {
                    nums[i] = 1;
                    cnt++;
                    flag = 0;
                }
            }
        }
        display(nums);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            res = i + 1;
        }
    }
    return res;
}

/*
 This solution is from BBS.
 After first elimination, all the numbers left are even numbers.
 Divide by 2, we get a continuous new sequence from 1 to n / 2.
 For this sequence we start from right to left as the first elimination.
 Then the original result should be two times the mirroring result of lastRemaining(n / 2).
 (this is also an important finding. E.g. [1,2,3,4,5], start from left to right you will finally get 2,
 but in reverse direction you will get 4. 2 and 4 are mirroring, their sum is exactly 6, that is 1+5)
 */
//int lastRemaining(int n) {
//    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
//}
int main(int argc, const char * argv[]) {
    cout<<lastRemaining(50)<<endl;
    return 0;
}
