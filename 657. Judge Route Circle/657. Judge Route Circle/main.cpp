//
//  main.cpp
//  657. Judge Route Circle
//
//  Created by Jie Lu on 2018/5/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool judgeCircle(string moves) {
    int up = 0, right = 0;
    for (char c : moves) {
        switch (c) {
            case 'U':
                up++;
                break;
            case 'D':
                up--;
                break;
            case 'L':
                right--;
                break;
            case 'R':
                right++;
                break;
        }
    }
    return up == 0 && right == 0 ? true : false;
}
int main(int argc, const char * argv[]) {
    if (judgeCircle("UURLDD")) {
        cout<<"yes"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
