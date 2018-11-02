//
//  main.cpp
//  537. Complex Number Multiplication
//
//  Created by Jie Lu on 2018/5/30.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
using namespace std;

pair<int, int> getAandB(const string& s) {
    int a, b , i, j;
    i = j = 0;
    while (s[j] != '+') {
        j++;
    }
    a = stoi(s.substr(i, j - i));
    i = j + 1;
    j++;
    while (s[j] != 'i') {
        j++;
    }
    b = stoi(s.substr(i, j - i));
    return make_pair(a, b);
}
string complexNumberMultiply(string a, string b) {
    auto s1 = getAandB(a), s2 = getAandB(b);
    string res;
    int x1 = s1.first, y1 = s1.second, x2 = s2.first, y2 = s2.second;
    // (x1 + y1i) * (x2 + y2i) = (x1 * x2 - y1 * y2) + (x1 * y2 + y1 * x2)i
    res += to_string(x1 * x2 - y1 * y2);
    res += "+";
    res += to_string(x1 * y2 + y1 * x2);
    res += "i";
    return res;
}
int main(int argc, const char * argv[]) {
    cout<<complexNumberMultiply("1+-1i", "1+-1i")<<endl;
    return 0;
}
