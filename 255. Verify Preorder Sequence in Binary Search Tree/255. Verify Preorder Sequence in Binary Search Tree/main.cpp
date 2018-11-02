//
//  main.cpp
//  255. Verify Preorder Sequence in Binary Search Tree
//
//  Created by Jie Lu on 2018/6/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// This solution is from BBS
bool verifyPreorder(vector<int>& preorder) {
    stack<int> stk;
    int lower_bound = INT_MIN;
    for(int i = 0; i < preorder.size(); i++){
        if(stk.empty() || preorder[i] < preorder[i - 1]){
            if(preorder[i] <= lower_bound)
                return false;
            stk.push(preorder[i]);
        }
        else{
            while(!stk.empty() && stk.top() < preorder[i]){
                lower_bound = stk.top();
                stk.pop();
            }
            stk.push(preorder[i]);
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    vector<int> preorder{5,2,1,3,6};
    if (verifyPreorder(preorder)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
