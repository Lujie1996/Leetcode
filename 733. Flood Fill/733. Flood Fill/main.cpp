//
//  main.cpp
//  733. Flood Fill
//
//  Created by Jie Lu on 2018/11/17.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor) {
        return;
    }
    
    image[sr][sc] = newColor;
    if (sr - 1 >= 0 && image[sr-1][sc] == oldColor) {
        dfs(image, sr-1, sc, newColor);
    }
    if (sr + 1 < image.size() && image[sr+1][sc] == oldColor) {
        dfs(image, sr+1, sc, newColor);
    }
    if (sc - 1 >= 0 && image[sr][sc-1] == oldColor) {
        dfs(image, sr, sc-1, newColor);
    }
    if (sc + 1 < image[0].size() && image[sr][sc+1] == oldColor) {
        dfs(image, sr, sc+1, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    dfs(image, sr, sc, newColor);
    return image;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> res = floodFill(image, 1, 1, 2);
    for (auto row : res) {
        for (auto a : row) {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
