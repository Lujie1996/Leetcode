//
//  main.cpp
//  904. Fruit Into Baskets
//
//  Created by Jie Lu on 2018/10/6.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int>& tree) {
    if (tree.size() == 0) {
        return 0;
    }
    
    int res = 0, i = 0, preI = 0, num1 = tree[0], num2 = tree[0], count = 0;
    while (i < tree.size()) {
        while (i < tree.size() && (tree[i] == num1 || tree[i] == num2)) {
            if (i > 0 && tree[i] != tree[i-1]) {
                preI = i;
            }
            i++;
            count++;
        }
        res = max(res, count);
        if (i == tree.size()) {
            break;
        }
        count = 0;
        num1 = num2;
        num2 = tree[i];
        i = preI;
    }
    return res;
}

int totalFruit2(vector<int>& tree) {
    if (tree.size() == 0) {
        return 0;
    }
    
    int num1 = tree[0], num2 = tree[0], res = 0, i = 0, j = 0, pre = 0;
    while (i < tree.size()) {
        while (i < tree.size() && (tree[i] == num1 || tree[i] == num2)) {
            if (i > 0 && tree[i] != tree[i-1]) {
                pre = i;
            }
            i++;
        }
        res = max(res, i-j);
        j = pre;
        if (i < tree.size()) {
            num1 = tree[pre];
            num2 = tree[i];
        }
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
//    vector<int> tree{3,3,3,1,2,1,1,2,3,3,4};
//    vector<int> tree{1,0,3,4,3};
//    vector<int> tree{1,2,3,2,2};
//    vector<int> tree{0,1,2,2};
    vector<int> tree{1,0,1,4,1,4,1,2,3};
    cout<<totalFruit2(tree)<<endl;
    return 0;
}
