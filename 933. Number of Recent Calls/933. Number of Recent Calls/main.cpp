//
//  main.cpp
//  933. Number of Recent Calls
//
//  Created by Jie Lu on 2018/11/16.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

class RecentCounter {
public:
    deque<int> time;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        time.push_back(t);
        while (!time.empty() && t - time.front() > 3000) {
            time.pop_front();
        }
        return time.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
