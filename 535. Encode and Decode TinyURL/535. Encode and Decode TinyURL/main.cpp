//
//  main.cpp
//  535. Encode and Decode TinyURL
//
//  Created by Jie Lu on 2018/6/1.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> encodeMap;
unordered_map<int, string> decodeMap;
// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    int intVal = (int)encodeMap.size() + 1;
    encodeMap[longUrl] = intVal;
    decodeMap[intVal] = longUrl;
    string tmp = "http://tinyurl.com/";
    return tmp + to_string(intVal);
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    int intVal = stoi(shortUrl.substr(19));
    return decodeMap[intVal];
}
int main(int argc, const char * argv[]) {
    string toEncode = "https://leetcode.com/problems/design-tinyurl";
    string s = encode(toEncode);
    if (decode(s) == toEncode) {
        cout<<s<<endl;
    }
    else {
        cout<<"Fault"<<endl;
    }
    
    // 以下测试hash<T>模版
    hash<string> str_hash;
    cout<<str_hash(toEncode)<<endl;
    // STl中包含一个std::hash<T>模版。对于string，一个hash<string>的对象例如str_hash可以通过传入string返回对应的哈希值。
    // 更一般的，unordered_set/map这些无序关联容器在处理自定义对象时，需要对象内提供两个函数/操作才能进行哈希散列：
    // 1. hash function（可以通过std::hash<T>定义）
    // 2. 判断相等的功能（可以通过重载操作符'=='）
    // 在string的例子中，hash和判等已经被包含在string类中，所以可以直接把string对象放入unordered_set/map中。
    // 相比之下，有序的关联容器例如set/map只需要提供判断对象小于的功能，一般通过重载操作符'<'完成。
    return 0;
}
