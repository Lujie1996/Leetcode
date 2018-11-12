//
//  main.cpp
//  636. Exclusive Time of Functions
//
//  Created by Jie Lu on 2018/11/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<pair<int, int>> st; // function id and start time
    map<int, int> timeCount;
    int midTime = 0;
    for (auto log : logs) {
        unsigned long index1 = log.find(':'), index2 = log.find(':', index1+1);
        string id = log.substr(0, index1), action = log.substr(index1+1, index2-index1-1), time = log.substr(index2+1);
        if (action == "start") {
            st.push({stoi(id), stoi(time)});
        }
        else {
            pair<int, int> top = st.top();
            st.pop();
            timeCount[top.first] = stoi(time) - top.second + 1 - midTime;
            midTime = timeCount[top.first];
        }
    }
    vector<int> res;
    for (auto row : timeCount) {
        res.push_back(row.second);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> res = exclusiveTime(2, logs);
    for (auto a : res) {
        cout<<a<<endl;
    }
    return 0;
}
