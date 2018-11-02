//
//  main.cpp
//  158. Read N Characters Given Read4 II - Call multiple times
//
//  Created by Jie Lu on 2018/10/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

queue<int> left;

int read(char *buf, int n) {
    int len = 0;
    int c;
    while (left.size() > 0) {
        buf[len++] = left.front();
        left.pop();
        if (len == n)
            return len;
    }
    
    while (len < n) {
        c = read4(buf+len);
        len += c;
        if (c < 4)
            break;
    }
    
    for (int i = n; i < len; i++) {
        left.push(buf[i]);
    }
    
    int e = min(len, n);
    buf[e] = '\0';
    return e;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
