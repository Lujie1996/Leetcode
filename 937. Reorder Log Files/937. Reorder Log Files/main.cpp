//
//  main.cpp
//  937. Reorder Log Files
//
//  Created by Jie Lu on 2018/11/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isLetterLog(string s) {
    int i = s.find(' ');
    if (isdigit(s[i+1])) {
        return false;
    }
    return true;
}

vector<string> reorderLogFiles(vector<string>& logs) {
    sort(logs.begin(), logs.end(), [](const string& a, const string& b){
        bool aIsLetterLog = isLetterLog(a), bIsLetterLog = isLetterLog(b);
        if (aIsLetterLog && !bIsLetterLog) {
            return true;
        }
        if (!aIsLetterLog && bIsLetterLog) {
            return false;
        }
        string aContent = a.substr(a.find(' ') + 1), bContent = b.substr(b.find(' ') + 1);
        if (aContent < bContent) {
            return true;
        }
        else if (aContent > bContent) {
            return false;
        }
        else {
            return a < b;
        }
    });
    return logs;
}

int main(int argc, const char * argv[]) {
    vector<string> logs{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    vector<string> res = reorderLogFiles(logs);
    for (auto a : res) {
        cout<<a<<endl;
    }
    return 0;
}
