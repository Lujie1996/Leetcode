//
//  main.cpp
//  984. String Without AAA or BBB
//
//  Created by Jie Lu on 2019/1/31.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

string strWithout3a3b(int A, int B) {
    string res;
    int sameCount = 0, pre = -1;
    while (A > 0 || B > 0) {
        if ((A >= B && sameCount < 2)|| (pre == 1 && sameCount == 2)) {
            if (pre == 0) {
                // previous chosen is 'a'
                sameCount += 1;
            }
            else {
                sameCount = 1;
                pre = 0;
            }
            res += 'a';
            A--;
        }
        else {
            if (pre == 1) {
                sameCount += 1;
            }
            else {
                sameCount = 1;
                pre = 1;
            }
            res += 'b';
            B--;
        }
        cout<<res<<endl;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout<<strWithout3a3b(4,1)<<endl;
    return 0;
}
