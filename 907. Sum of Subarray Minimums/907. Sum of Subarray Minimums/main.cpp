//
//  main.cpp
//  907. Sum of Subarray Minimums
//
//  Created by Jie Lu on 2019/1/24.
//  Copyright © 2019 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int sumSubarrayMins(vector<int>& A) {
    vector<int> left(A.size(), -1), right(A.size(), A.size());
    stack<pair<int,int>> st; // {num,index}
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top().first > A[i]) {
            right[st.top().second] = i;
            st.pop();
        }
        st.push({A[i], i});
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = A.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= A[i]) {
            left[st.top().second] = i;
            st.pop();
        }
        st.push({A[i], i});
    }
    
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        cout<<i<<" "<<i-left[i]<<" "<<right[i]-i<<endl;
        sum += (i-left[i]) * (right[i]-i) * A[i];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    vector<int> A{71,55,82,55};
    cout<<sumSubarrayMins(A)<<endl;
    return 0;
}
