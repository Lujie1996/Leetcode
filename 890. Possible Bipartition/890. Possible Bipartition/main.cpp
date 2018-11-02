//
//  main.cpp
//  890. Possible Bipartition
//
//  Created by Jie Lu on 2018/8/13.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// 问题本质：图是否可以二分。用上色法做。
bool paintNodeValid(vector<vector<int>>& edges, vector<int>& nodeColor, int node, int colorToPaint) {
    // unpainted: 0; painted: -1 or 1.
    if (nodeColor[node] != 0) {
        return nodeColor[node] != colorToPaint;
    }
    nodeColor[node] = colorToPaint;
    for(int i = 0; i < edges[node].size(); i++) {
        if(!paintNodeValid(edges, nodeColor, edges[node][i], colorToPaint * -1)) {
            return false;
        }
    }
    return true;
}
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> edges(N+1, vector<int>());
    vector<int> start{0,1};
    dislikes.push_back(start);
    // use a fake node to start the dfs
    for (auto dislike : dislikes) {
        edges[dislike[0]].push_back(dislike[1]);
    }
    vector<int> nodeColor(N+1, 0);
    return paintNodeValid(edges, nodeColor, 0, 1);
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> dislikes{{1,2},{2,3},{3,4},{4,5},{5,1}};
    if (possibleBipartition(5, dislikes)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
