//
//  main.cpp
//  379. Design Phone Directory
//
//  Created by Jie Lu on 2018/12/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PhoneDirectory {
private:
    vector<bool> used;
    int curNum = 0;
public:
    /** Initialize your data structure here
     @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        used.resize(maxNumbers, false);
    }
    
    /** Provide a number which is not assigned to anyone.
     @return - Return an available number. Return -1 if none is available. */
    int get() {
        while (used[curNum]) {
            curNum = (curNum + 1) % used.size();
        }
        used[curNum] = true;
        int res = curNum;
        curNum = (curNum + 1) % used.size();
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        used[number] = false;
    }
};

int main(int argc, const char * argv[]) {
    PhoneDirectory obj(1);
    cout<<obj.check(0)<<endl;
    cout<<obj.get()<<endl;
    cout<<obj.check(0)<<endl;
    cout<<obj.get()<<endl;
    return 0;
}
