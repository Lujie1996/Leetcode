//
//  main.cpp
//  339. Nested List Weight Sum
//
//  Created by Jie Lu on 2018/7/5.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**
 *  This is the interface that allows for creating nested lists.
 *  You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *      Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *      Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *      Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *      Return the single integer that this NestedInteger holds, if it holds a single integer
 *      The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *      Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *      Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *      Return the nested list that this NestedInteger holds, if it holds a nested list
 *      The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int dfs(vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto x : nestedList) {
            if (x.isInteger()) {
                sum += x.getInteger() * depth;
            }
            else {
                sum += dfs(x.getList(), depth + 1);
            }
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
