//
//  main.cpp
//  85. Maximal Rectangle
//
//  Created by Jie Lu on 2018/12/14.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    
}
int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
    cout<<maximalRectangle(matrix)<<endl;
    
    return 0;
}
