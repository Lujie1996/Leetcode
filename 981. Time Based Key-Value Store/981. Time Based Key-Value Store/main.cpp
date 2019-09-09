//
//  main.cpp
//  981. Time Based Key-Value Store
//
//  Created by Jie Lu on 2019/1/31.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string, greater<int>>> myhashtable;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string k, string v, int t) {
        myhashtable[k][t] = v;
    }
    
    string get(string k, int t) {
        if (myhashtable.find(k) == myhashtable.end()) {
            return "";
        }
        
        auto ite = myhashtable[k].lower_bound(t);
        if (ite == myhashtable[k].end()) {
            return "";
        }
        return ite->second;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
