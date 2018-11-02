//
//  main.cpp
//  307. Range Sum Query - Mutable
//
//  Created by Jie Lu on 2018/5/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;

// Binary Indexed Tree (树状数组)
//class NumArray {
//public:
//    int n = 0;
//    vector<int> sum;
//    vector<int> a;
//    // Note that sum starts from index 1, while a starts from index 0
//    NumArray(vector<int> nums) {
//        a = vector<int>(nums.size(), 0);
//        n = (int)nums.size();
//        sum = vector<int>(nums.size() +1 , 0);
//        for (int i = 0; i < nums.size(); i++) {
//            update(i, nums[i]);
//        }
//    }
//
//    void update(int i, int val) {
//        int diff = val - a[i];
//        a[i] = val;
//        i += 1;
//        while(i <= n) {
//            sum[i] += diff;
//            i += (i & (-i));
//        }
//    }
//
//    int query(int x) {
//        x += 1;
//        int res = 0;
//        while(x != 0) {
//            res += sum[x];
//            x -= (x & (-x));
//        }
//        return res;
//    }
//
//    int sumRange(int i, int j) {
//        return query(j) - query(i - 1);
//    }
//};

// Segment Tree
class NumArray {
public:
    struct SegmentNode {
        int start, end, sum;
        SegmentNode *left, *right;
        SegmentNode(int a, int b) : start(a), end(b), sum(0) {};
    };
    SegmentNode *root;
    
    SegmentNode* buildSegmentTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        SegmentNode *node = new SegmentNode(start, end);
        if (start == end) {
            node->sum = nums[start];
            return node;
        }
        int mid = (start + end) / 2;
        node->left = buildSegmentTree(nums, start, mid);
        node->right = buildSegmentTree(nums, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    
    void updateSegmentNode(SegmentNode *node, int pos, int val) {
        if (node->start == node->end && pos == node->start) {
            node->sum = val;
            return;
        }
        if (pos < node->start || pos > node->end) {
            return;
        }
        int mid = (node->start + node->end) / 2;
        if (pos <= mid) {
            updateSegmentNode(node->left, pos, val);
        }
        else {
            updateSegmentNode(node->right, pos, val);
        }
        node->sum = node->left->sum + node->right->sum;
    }
    
    int sumRangeInSegmentTree(SegmentNode *node, int start, int end) {
        if (node->start == start && node->end == end) {
            return node->sum;
        }
        int mid = (node->start + node->end) / 2;
        if (end <= mid) {
            return sumRangeInSegmentTree(node->left, start, end);
        }
        else if (start > mid) {
            return sumRangeInSegmentTree(node->right, start, end);
        }
        else
            return sumRangeInSegmentTree(node->left, start, mid) + sumRangeInSegmentTree(node->right, mid + 1, end);
    }
    
    NumArray(vector<int> nums) {
        root = buildSegmentTree(nums, 0, (int)nums.size() - 1);
    }
    
    void update(int i, int val) {
        updateSegmentNode(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRangeInSegmentTree(root, i, j);
    }
};

int main(int argc, const char * argv[]) {
    int a[] = {0,9,5,7,3};
    vector<int> nums(a, a+5);
    NumArray test(nums);
    cout<<test.sumRange(4, 4)<<endl;
    cout<<test.sumRange(2, 4)<<endl;
    cout<<test.sumRange(3, 3)<<endl;
    test.update(4, 5);
    test.update(1, 7);
    test.update(0, 8);
    cout<<test.sumRange(1, 2)<<endl;
    cout<<test.sumRange(0, 0)<<endl;
    test.update(1, 9);
    cout<<test.sumRange(4, 4)<<endl;
    cout<<test.sumRange(3, 4)<<endl;
    return 0;
}
