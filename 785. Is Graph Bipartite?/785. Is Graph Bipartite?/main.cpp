//
//  main.cpp
//  785. Is Graph Bipartite?
//
//  Created by Jie Lu on 2018/11/10.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool isValidToPaint(vector<vector<int>>& graph, vector<int>& color, int node, int colorToPaint) {
    if (color[node] != 0 && color[node] != colorToPaint) {
        return false;
    }
    if (color[node] != 0 && color[node] == colorToPaint) {
        return true;
    }
    
    color[node] = colorToPaint;
    for (auto next : graph[node]) {
        if (!isValidToPaint(graph, color, next, color[node]*-1)) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), 0);
    // 0 is uncolored. 1 and -1 are two colors
    
    for (int i = 0; i < graph.size(); i++) {
        if (color[i] == 0) {
            if (!isValidToPaint(graph, color, i, 1)) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
