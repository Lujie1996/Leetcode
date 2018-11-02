//
//  main.cpp
//  815. Bus Routes
//
//  Created by Jie Lu on 2018/4/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    unordered_map<int, unordered_set<int>> routeStops, stopRoutes;
    unordered_map<int, int> numBusesToThisStop;
    for (int i = 0; i < routes.size(); i++) {
        for (int j = 0; j < routes[i].size(); j++) {
            routeStops[i].insert(routes[i][j]);
            stopRoutes[routes[i][j]].insert(i);
            numBusesToThisStop[routes[i][j]] = 0;
        }
    }
    queue<int> reachableStopsQueue;
    unordered_set<int> visitedRoutes;
    reachableStopsQueue.push(S);
    int count = 0;
    while (!reachableStopsQueue.empty()) {
        count += 1;
        int thisStop = reachableStopsQueue.front();
        reachableStopsQueue.pop();
        if (thisStop == T) {
            return numBusesToThisStop[T];
        }
        for (auto route : stopRoutes[thisStop]) {
            if (visitedRoutes.find(route) != visitedRoutes.end()) {
                continue;
            }
            for (auto stop : routeStops[route]) {
                if (stop != thisStop) {
                    reachableStopsQueue.push(stop);
                    if (numBusesToThisStop[stop] == 0) {
                        numBusesToThisStop[stop] = numBusesToThisStop[thisStop] + 1;
                    }
                }
            }
            visitedRoutes.insert(route);
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> routes;
    int a[] = {1,2,3,4}, b[] = {5,6,3,7};
    vector<int> r1(a, a+4), r2(b, b+4);
    routes.push_back(r1);
    routes.push_back(r2);
    cout<<numBusesToDestination(routes, 1, 6)<<endl;
    return 0;
}
