//
//  main.cpp
//  371. Sum of Two Integers
//
//  Created by Jie Lu on 2018/6/15.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int getSum(int a, int b) {
    int flag = 0, i = 0, mask = 1,  x= 0, y = 0, res = 0;
    while (i < 32) {
        x = (a >> i) & mask;
        y = (b >> i) & mask;
        if (x == 0 && y == 0) {
            res |= (flag << i);
            flag = 0;
        }
        else if (x == 1 && y == 1) {
            res |= (flag << i);
            flag = 1;
        }
        else {
            if (flag == 1) {
                res |= (0 << i);
            }
            else {
                res |= (1 << i);
            }
        }
        i++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<getSum(3, 5)<<endl;
    return 0;
}
