//
//  main.cpp
//  777. Swap Adjacent in LR String
//
//  Created by Jie Lu on 2018/10/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

bool canTransform(string start, string end) {
    if (start.size() != end.size()) {
        return false;
    }
    
    int i = 0, j = 0;
    while (i < start.size() && j < end.size()) {
        while (i < start.size() && start[i] == 'X') {
            i++;
        }
        while (j < end.size() && end[j] == 'X') {
            j++;
        }
        if (start[i] != end[j] || start[i] == 'L' && i < j || start[i] == 'R' && i > j) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
