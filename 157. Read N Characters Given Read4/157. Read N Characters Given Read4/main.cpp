//
//  main.cpp
//  157. Read N Characters Given Read4
//
//  Created by Jie Lu on 2018/10/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int read(char *buf, int n) {
    if (n == 0) {
        return 0;
    }
    
    int res = 0, cur = 4;
    for(int i = 0; i <= n/4 && cur == 4; i++){
        cur = read4(buf + res);
        res += cur;
    }
    return min(res, n);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
