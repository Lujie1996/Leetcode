//
//  main.cpp
//  490. The Maze
//
//  Created by Jie Lu on 2018/9/22.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> maze{{0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}};
    vector<int> start{0, 4}, destination{4, 4};
    cout<<hasPath(maze, start, destination)<<endl;
    return 0;
}
