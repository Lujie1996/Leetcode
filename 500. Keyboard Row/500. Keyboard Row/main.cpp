//
//  main.cpp
//  500. Keyboard Row
//
//  Created by Jie Lu on 2018/6/2.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> findWords(vector<string>& words) {
    vector<string> res;
    //           A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    int row[] = {1,0,0,1,2,1,1,1,2,1,1,1,0,0,2,2,2,2,1,2,2,0,2,0,2,0};
    for (auto s : words) {
        int rowNo = row[tolower(s[0]) - 'a'], i = 1;
        for (; i < s.size(); i++) {
            if (rowNo != row[tolower(s[i]) - 'a']) {
                break;
            }
        }
        if (i == (int)s.size()) {
            res.push_back(s);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
    vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
    vector<string> res = findWords(words);
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
