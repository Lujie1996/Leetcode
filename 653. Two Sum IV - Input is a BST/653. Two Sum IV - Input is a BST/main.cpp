//
//  main.cpp
//  653. Two Sum IV - Input is a BST
//
//  Created by Jie Lu on 2018/10/7.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>

void inorder(vector<int>& nums, TreeNode* root) {
    if (!root) {
        return;
    }
    inorder(nums, root->left);
    nums.push_back(root->val);
    inorder(nums, root->right);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(nums, root);
    
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        if (nums[low] + nums[high] == k) {
            return true;
        }
        if (nums[low] + nums[high] < k) {
            low++;
        }
        else {
            high--;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
