//
//  main.cpp
//  551. Student Attendance Record I
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool checkRecord(string s) {
    int countA = 0, countContinuousL = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == 'L') {
            countContinuousL++;
            if (countContinuousL == 3) {
                return false;
            }
        }
        else if (c == 'A') {
            countContinuousL = 0;
            if (countA == 1) {
                return false;
            }
            else {
                countA = 1;
            }
        }
        else {
            countContinuousL = 0;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (checkRecord("PPALAP")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
