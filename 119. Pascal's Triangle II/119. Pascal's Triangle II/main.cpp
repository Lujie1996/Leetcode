//
//  main.cpp
//  119. Pascal's Triangle II
//
//  Created by Jie Lu on 2018/4/21.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// Although it becomes more complex using t and preNum, doing like this saves space.
// Otherwise we need another vector to store preRow, but now we just modify a vector in place.
vector<int> getRow(int rowIndex) {
    vector<int> row(1,1);
    if (rowIndex == 0) {
        return row;
    }
    int preNum = 1;
    for (int i = 1; i <= rowIndex; i++) {
        row.push_back(0);
        for (int j = 0; j < i - 1; j++) {
            int t = preNum + row[j+1]; //the new value which is to be put on row[j+1]
            preNum = row[j+1]; //since row[j+1] will soon be changed, record its original value
            row[j+1] = t;
        }
        row[i] = 1;
    }
    return row;
}
int main(int argc, const char * argv[]) {
    int rowIndex;
    cin>>rowIndex;
    vector<int> res = getRow(rowIndex);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
