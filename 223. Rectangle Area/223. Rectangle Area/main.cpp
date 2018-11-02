//
//  main.cpp
//  223. Rectangle Area
//
//  Created by Jie Lu on 2018/5/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int I,J,K,L;
    if(E>C||F>D||A>G||B>H)
        return (C-A)*(D-B) + (G-E)*(H-F);
    else{
        I = max(A,E);
        J = min(C,G);
        K = max(B,F);
        L = min(D,H);
        return (C-A)*(D-B) + (G-E)*(H-F) - (J-I)*(L-K);
    }
}
int main(int argc, const char * argv[]) {
    cout<<computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1)<<endl;
    return 0;
}
