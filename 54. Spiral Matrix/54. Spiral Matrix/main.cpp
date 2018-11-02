//
//  main.cpp
//  54. Spiral Matrix
//
//  Created by Jie Lu on 2018/3/31.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size() == 0)
        return res;
    int index = 0;
    int leftLimit=0, rightLimit=(int)matrix[0].size()-1, upLimit=0, downLimit=(int)matrix.size()-1;
    
    while(true) {
        if(leftLimit > rightLimit)
            return res;
        else{
            for(index=leftLimit;index<=rightLimit;index++)
                res.push_back(matrix[upLimit][index]);
            upLimit+=1;
        }
       
        if(upLimit > downLimit)
            return res;
        else{
            for(index=upLimit;index<=downLimit;index++)
                res.push_back(matrix[index][rightLimit]);
            rightLimit-=1;
        }
        
        if(rightLimit < leftLimit)
            return res;
        else{
            for(index=rightLimit;index>=leftLimit;index--)
                res.push_back(matrix[downLimit][index]);
            downLimit-=1;
        }
       
        if(downLimit < upLimit)
            return res;
        else{
            for(index=downLimit;index>=upLimit;index--)
                res.push_back(matrix[index][leftLimit]);
            leftLimit+=1;
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    int nums[] = {1,2,3,4,5,6,7,8,9};
    vector<int> row1(nums,nums+3);
    vector<int> row2(nums+3,nums+6);
    vector<int> row3(nums+6,nums+9);
    vector<vector<int>> matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
//    matrix.push_back(row3);
    vector<int> res = spiralOrder(matrix);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}
