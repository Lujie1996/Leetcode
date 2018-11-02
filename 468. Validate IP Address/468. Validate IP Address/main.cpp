//
//  main.cpp
//  468. Validate IP Address
//
//  Created by Jie Lu on 2018/10/11.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> splitString(string s, char c) {
    istringstream iss(s);
    vector<string> res;
    string sub;
    while (getline(iss, sub, c)) {
        res.push_back(sub);
    }
    if (s[s.size()-1] == c) {
        res.push_back("");
    }
    return res;
}

bool validSub4(string sub) {
    if (sub.size() == 0 || sub.size() > 3) {
        return false;
    }
    if (sub.size() > 1 && sub[0] == '0') {
        // leading zero
        return false;
    }
    for (auto c : sub) {
        if (!isdigit(c)) {
            return false;
        }
    }
    int num = stoi(sub);
    return num <= 255;
}

bool validSub6(string sub) {
    if (sub.size() == 0 || sub.size() > 4) {
        return false;
    }
    for (auto c : sub) {
        c = tolower(c);
        if (isdigit(c) || (c >= 'a' && c <= 'f')) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

string validIPAddress(string IP) {
    vector<string> subs;
    if (IP.find(':') == -1) {
        // IPv4
        subs = splitString(IP, '.');
        if (subs.size() != 4) {
            return "Neither";
        }
        for (auto sub : subs) {
            if (!validSub4(sub)) {
                return "Neither";
            }
        }
        return "IPv4";
    }
    else {
        // IPv6
        subs = splitString(IP, ':');
        if (subs.size() != 8) {
            return "Neither";
        }
        for (auto sub : subs) {
            if (!validSub6(sub)) {
                return "Neither";
            }
        }
        return "IPv6";
    }
}

int main(int argc, const char * argv[]) {
    cout<<validIPAddress("1e1.4.5.6")<<endl;
    return 0;
}
