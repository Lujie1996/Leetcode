//
//  main.cpp
//  251. Flatten 2D Vector
//
//  Created by Jie Lu on 2018/6/9.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
    vector<vector<int>> vec;
    int i,j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
        i = 0;
        j = 0;
    }
    
    int next() {
        return vec[i][j++];
    }
    
    bool hasNext() {
        while (i < vec.size() && j == vec[i].size()) {
            i++;
            j = 0;
        }
        return i != vec.size();
    }
};
// Another solution from BBS.
//class Vector2D {
//    vector<vector<int>>::iterator i, iEnd;
//    int j = 0;
//public:
//    Vector2D(vector<vector<int>>& vec2d) {
//        i = vec2d.begin();
//        iEnd = vec2d.end();
//    }
//
//    int next() {
//        return (*i)[j++];
//    }
//
//    bool hasNext() {
//        while (i != iEnd && j == (*i).size()) {
//            i++;
//            j = 0;
//        }
//        return i != iEnd;
//    }
//};
int main(int argc, const char * argv[]) {
    vector<int> a{1,2,3}, b{4,5};
    vector<vector<int>> vec2d{a,b};
    Vector2D i(vec2d);
    while (i.hasNext())
        cout << i.next();
    cout<<endl;
    return 0;
}
