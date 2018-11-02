//
//  main.cpp
//  702. Search in a Sorted Array of Unknown Size
//
//  Created by Jie Lu on 2018/9/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// ArrayReader.get(k)
class ArrayReader {
private:
    vector<int> nums;
public:
    int get(int k) {
        if (k >= nums.size()) {
            return INT_MAX;
        }
        if (k < 0) {
            return INT_MIN;
        }
        return nums[k];
    }
    
    ArrayReader(vector<int> input) {
        nums = input;
    }
};


int search(ArrayReader& reader, int target) {
    int left = 0, right = 0;
    while (reader.get(right)  < target) {
        left = right;
        right = right == 0 ? 1 : right * 2;
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        int midNum = reader.get(mid);
        if (midNum == target) {
            return mid;
        }
        else if (midNum > target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return reader.get(left) == target ? left : -1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums{-1,0,3,5,9,12};
    ArrayReader reader(nums);
    cout<<search(reader, 9)<<endl;
    return 0;
}
