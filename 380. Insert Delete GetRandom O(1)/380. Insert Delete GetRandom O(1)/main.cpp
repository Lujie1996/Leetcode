//
//  main.cpp
//  380. Insert Delete GetRandom O(1)
//
//  Created by Jie Lu on 2019/1/7.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> numIndex;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (numIndex.find(val) != numIndex.end()) {
            return false;
        }
        nums.push_back(val);
        numIndex[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (numIndex.find(val) == numIndex.end()) {
            return false;
        }
        int tailNum = nums.back();
        int index = numIndex[val];
        nums[index] = tailNum;
        numIndex[tailNum] = index;
        nums.pop_back();
        numIndex.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
