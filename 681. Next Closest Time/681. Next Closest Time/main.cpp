//
//  main.cpp
//  681. Next Closest Time
//
//  Created by Jie Lu on 2018/5/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string buildReturn(vector<int>& nums, int index, int greater) {
    string res;
    int minNum = INT_MAX, i = 0;
    for (auto num : nums) {
        minNum = min(minNum, num);
    }
    nums[index] = greater;
    for (int i = index + 1; i <= 3; i++) {
        nums[i] = minNum;
    }
    for (; i < 2; i++) {
        res += to_string(nums[i]);
    }
    res += ":";
    for (; i < 4; i++) {
        res += to_string(nums[i]);
    }
    return res;
}
int nextGreater(const vector<int>& nums, int num) {
    // return the next number greater than num in all nums
    // if not exists, return -1
    int res = INT_MAX;
    for (auto x : nums) {
        if (x > num) {
            res = min(x, res);
        }
    }
    return res == INT_MAX ? -1 : res;
}
vector<int> getTimeVector(string time) {
    // transform string-type time to a vector of int with length = 4 representing four digits of time
    vector<int> t(4, 0);
    t[0] = time[0] - '0';
    t[1] = time[1] - '0';
    t[2] = time[3] - '0';
    t[3] = time[4] - '0';
    return t;
}
string nextClosestTime(string time) {
    vector<int> t = getTimeVector(time);
    // get a four-digit-long vector to store all digits in time, including 0s.
    int limit[] = {2,3,5,9}, i = 0;
    // limit[i] is the max allowed number of digit t[i]. Note that cases like 09:23 should be treated alone.
    string res;
    for (i = 3; i >= 0; i--) {
        int greater = nextGreater(t, t[i]);
        if (greater != -1 && (greater <= limit[i] || (i == 1 && t[0] != 2 && greater <= 9))) {
            // t[1] can be 0..9 when t[0] == 0 or 1. i.e.: 09:22, 19:22,...
            res = buildReturn(t, i, greater);
            // replace t[i] with greater, then replace all digits following t[i] with the min number of all t[0..3]
            break;
        }
    }
    if (i == -1) {
        // In this case, all time within this day is not valid. The earliest time on the next day is the result.
        res = buildReturn(t, -1, 0);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<nextClosestTime("20:48")<<endl;
    return 0;
}
