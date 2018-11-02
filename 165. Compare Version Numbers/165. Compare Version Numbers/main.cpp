//
//  main.cpp
//  165. Compare Version Numbers
//
//  Created by Jie Lu on 2018/4/27.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// My code in 2018/4/27
//vector<string> split(string str, char c = ' ') {
//    vector<string> res;
//    int pre = 0;
//    for (int i = 0; i < str.length(); i++) {
//        if (str[i] == c) {
//            res.push_back(str.substr(pre, i - pre));
//            pre = i + 1;
//        }
//        else if (i == str.length() - 1) {
//            res.push_back(str.substr(pre, i - pre + 1));
//        }
//    }
//    return res;
//}
//int compareVersion(string version1, string version2) {
//    vector<string> v1 = split(version1, '.');
//    vector<string> v2 = split(version2, '.');
//    int v1Len = (int)v1.size();
//    int v2Len = (int)v2.size();
//    int i = 0, maxLen = max(v1Len, v2Len);
//    int v1field, v2field;
//    while (i < maxLen) {
//        if (i < v1Len) {
//            v1field = stoi(v1[i]);
//        }
//        else {
//            v1field = 0;
//        }
//        if (i < v2Len) {
//            v2field = stoi(v2[i]);
//        }
//        else {
//            v2field = 0;
//        }
//        if (v1field > v2field) {
//            return 1;
//        }
//        else if (v1field < v2field) {
//            return -1;
//        }
//        else if (i + 1 == maxLen){
//            return 0;
//        }
//        i++;
//    }
//    return 1;
//}


// My code in 2018/10/31
vector<int> partitionVersion(string version) {
    vector<int> res;
    int i = 0;
    while (i < version.size()) {
        int num = 0;
        while (i < version.size() && isdigit(version[i])) {
            num *= 10;
            num += version[i] - '0';
            i++;
        }
        res.push_back(num);
        i++;
    }
    return res;
}

bool allZero(vector<int>& nums, int start) {
    for (int i = start; i < nums.size(); i++) {
        if (nums[i] != 0) {
            return false;
        }
    }
    return true;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = partitionVersion(version1), v2 = partitionVersion(version2);
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] > v2[j]) {
            return 1;
        }
        else if (v1[i] < v2[j]) {
            return -1;
        }
        i++;
        j++;
    }
    if (i != v1.size() && j == v2.size() && !allZero(v1, i)) {
        return 1;
    }
    if (i == v1.size() && j != v2.size() && !allZero(v2, j)) {
        return -1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    cout<<compareVersion("1.0", "1")<<endl;
    return 0;
}
