//
//  main.cpp
//  401. Binary Watch
//
//  Created by Jie Lu on 2018/7/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void getHour(vector<string>& res, int cur, int k, int start) {
    if (k == 0) {
        res.push_back(to_string(cur));
        return;
    }
    int options[] = {1,2,4,8};
    for (int i = start; i <= 4 - k ; i++) {
        if (cur + options[i] <= 11) {
            getHour(res, cur + options[i], k - 1, i + 1);
        }
    }
}
void getMinutes(vector<string>& res, int cur, int k, int start) {
    if (k == 0) {
        string s = to_string(cur);
        if (cur < 10) {
            s = "0" + s;
        }
        res.push_back(s);
        return;
    }
    int options[] = {1,2,4,8,16,32};
    for (int i = start; i <= 6 - k ; i++) {
        if (cur + options[i] <= 59) {
            getMinutes(res, cur + options[i], k - 1, i + 1);
        }
    }
}
vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for (int i = 0; i <= num; i++) {
        // i LEDs on for hour, num-i LEDs on for minute
        vector<string> hours, minutes;
        getHour(hours, 0, i, 0);
        getMinutes(minutes, 0, num - i, 0);
        for (auto h : hours) {
            for (auto m : minutes) {
                res.push_back(h + ":" + m);
            }
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> res = readBinaryWatch(3);
    for (auto s : res) {
        cout<<s<<endl;
    }
    cout<<endl;
    return 0;
}
