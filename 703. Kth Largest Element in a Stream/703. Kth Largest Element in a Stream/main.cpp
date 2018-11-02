//
//  main.cpp
//  703. Kth Largest Element in a Stream
//
//  Created by Jie Lu on 2018/9/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    int heapSize;
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    KthLargest(int k, vector<int> nums) {
        heapSize = k;
        int i = 0;
        while (heap.size() < k && i < nums.size()) {
            heap.push(nums[i++]);
        }
        while (i < nums.size()) {
            add(nums[i++]);
        }
    }
    
    int add(int val) {
        if (heap.size() < heapSize) {
            heap.push(val);
        }
        else if (val > heap.top()) {
            heap.pop();
            heap.push(val);
        }
        return heap.top();
    }
};

int main(int argc, const char * argv[]) {
    KthLargest obj(3,{1,2,3,4,5});
    cout<<obj.add(0)<<endl; // 3
    return 0;
}
