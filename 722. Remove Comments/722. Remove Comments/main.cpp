//
//  main.cpp
//  722. Remove Comments
//
//  Created by Jie Lu on 2018/9/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void findIndex(string s, int& blockIndex, int& lineIndex) {
    blockIndex = lineIndex = -1;
    for (int i = 0; i < s.size() - 1; i++) {
        string twoChar = s.substr(i,2);
        if (twoChar == "//" && lineIndex == -1) {
            lineIndex = i;
        }
        else if (twoChar == "/*" && blockIndex == -1) {
            blockIndex = i;
        }
    }
}

// 因为blockComment嵌入的代码同行前后可能有非comment代码，例如在注释最后一行是这个样子：aaaa*/asas//as，这样这行代码还需要返回外层函数去处理
// 这里removeBlockComment完成的处理是：将block包围起来的注释删除，保留注释前后同行的代码，并将它们放置注释块的最后一行
// 当存在注释块前后同行的代码时，将row返回到注释块最后一行的位置，让外层函数继续处理（返回时row = i - 1， 因为返回外层循环时row会自增）
void removeBlockComment(vector<string>& source, int& row, int blockIndex, vector<string>& res) {
    string beforeBlock = source[row].substr(0, blockIndex);
    for (int i = row; i < source.size(); i++) {
        int j = i == row ? blockIndex + 2 : 0;
        while (j < source[i].size()) {
            string twoChar = source[i].substr(j, 2);
            if (twoChar == "*/") {
                string afterBlock = j + 2 < source[i].size() ? source[i].substr(j+2) : "";
                source[i] = beforeBlock + afterBlock;
                if (source[i] != "") {
                    row = i - 1; // since i++ in outer loop, set row = i - 1 to let outer loop handle the concatenated source[i]
                }
                else {
                    row = i;
                }
                return;
            }
            j++;
        }
    }
}

vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    for (int i = 0; i < source.size(); i++) {
        int blockIndex, lineIndex;
        findIndex(source[i], blockIndex, lineIndex);
        if (blockIndex == -1 && lineIndex == -1) {
            // there isn't // or */
            res.push_back(source[i]);
        }
        else if (lineIndex >= 0 && (blockIndex == -1 || blockIndex > lineIndex)) {
            // there is // and (no /* or /* is included after //)
            if (lineIndex > 0) {
                res.push_back(source[i].substr(0, lineIndex));
            }
        }
        else if (blockIndex >= 0 && (lineIndex == -1 || lineIndex > blockIndex)) {
            // there is /* and (no // or // is included after /*)
            removeBlockComment(source, i, blockIndex, res);
        }
    }
    return res;
}
int main(int argc, const char * argv[]) {
//    vector<string> source{"a/*comment", "line", "more_comment*/b"};
    vector<string> source{"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
//    vector<string> source{"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};
//    vector<string> source{"a/*/b//*c","blank","d/*/e*//f"};
    vector<string> res = removeComments(source);
    for (auto s : res) {
        cout<<s<<endl;
    }
    return 0;
}
