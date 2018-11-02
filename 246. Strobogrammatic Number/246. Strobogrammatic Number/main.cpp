//
//  main.cpp
//  246. Strobogrammatic Number
//
//  Created by Jie Lu on 2018/6/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool isStrobogrammatic(string num) {
    int match[] = {0,1,-1,-1,-1,-1,9,-1,8,6};
    int i = 0, j = (int)num.size() - 1;
    while (i <= j) {
        if (match[num[i++] - '0'] != num[j--] - '0') {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    if (isStrobogrammatic("609")) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
