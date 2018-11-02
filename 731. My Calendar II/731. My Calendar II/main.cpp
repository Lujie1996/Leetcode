//
//  main.cpp
//  731. My Calendar II
//
//  Created by Jie Lu on 2018/9/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

class MyCalendarTwo {
private:
    set<pair<int, int>> noOverlap, onceOverlap;
public:
    MyCalendarTwo() {
        
    }
    
    // 记住活动安排这类问题中判断重叠的方式
    // 正向表示重叠比较困难，用反向的思维考虑
    // 对如下条件取反就是重叠了：A在B的结束之后开始或者A在B的开始之前结束
    bool book(int start, int end) {
        for (auto t : onceOverlap) {
            if (start >= t.second || end <= t.first) {
                // 在某个活动的结束之后开始或者它的开始之前结束
                continue;
            }
            else {
                return false;
            }
        }
        
        for (auto t : noOverlap) {
            if (start >= t.second || end <= t.first) {
                continue;
            }
            else {
                onceOverlap.insert({max(start, t.first), min(end, t.second)});
            }
        }
        noOverlap.insert({start, end});
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
