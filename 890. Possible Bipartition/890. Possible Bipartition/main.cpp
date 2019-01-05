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

bool paintNodeValid(vector<vector<int>>& graph, vector<int>& nodeColor, int node, int colorToPaint) {
    // unpainted: 0; painted: -1 or 1.
    if (nodeColor[node] != 0) {
        return nodeColor[node] == colorToPaint;
    }
    nodeColor[node] = colorToPaint;
    
    for(auto neighbor : graph[node]) {
        if(!paintNodeValid(graph, nodeColor, neighbor, colorToPaint * -1)) {
            return false;
        }
    }
    return true;
}
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N+1);

    for (auto dislike : dislikes) {
        graph[dislike[0]].push_back(dislike[1]);
        graph[dislike[1]].push_back(dislike[0]);
        // IMPORTANT!!!
    }
    vector<int> nodeColor(N+1, 0);
    for (int i = 1; i < N + 1; i++) {
        if (nodeColor[i] == 0 && !paintNodeValid(graph, nodeColor, i, 1)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
//    vector<vector<int>> dislikes{{1,2},{2,3},{3,4},{4,5},{5,1}};
    vector<vector<int>> dislikes{{1,2},{3,4},{4,5},{3,5}};
    if (possibleBipartition(5, dislikes)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    return 0;
}
