//
//  main.cpp
//  273. Integer to English Words
//
//  Created by Jie Lu on 2018/9/8.
//  Copyright © 2018 Jie Lu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string convertThree(string s) {
    string res;
    vector<string> below10{"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    vector<string> ten220{"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tens{"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    if (s.size() == 1) {
        s = "00" + s;
    }
    else if (s.size() == 2) {
        s = "0" + s;
    }
    
    int high = stoi(s.substr(0,1));
    int last2 = stoi(s.substr(1));
    
    if (high != 0) {
        res += (below10[high] + " Hundred");
        if (last2 != 0) {
            res += " ";
        }
    }
    
    if (last2 < 10) {
        res += (below10[last2]);
    }
    else if (last2 > 9 && last2 < 20) {
        res += (ten220[last2-10]);
    }
    else {
        int mid = s[1] - '0', low = s[2] - '0';
        res += (tens[mid-2]);
        if (low != 0) {
            res += " ";
        }
        res += (below10[low]);
    }
    return res;
}
string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }
    string s = to_string(num);
    string res;
  
    int end = (int)s.size();
    int count = 0;
    vector<string> thousands{"", "Thousand","Million","Billion"};
    
    while (end > 0) {
        int start = end - 3 >= 0 ? end - 3 : 0;
        string threeDigits = s.substr(start,end-start);
        end = start;
        string threeConverted = convertThree(threeDigits);
    
        if (count == 0) {
            res = threeConverted;
        }
        else {
            res = threeConverted + (threeConverted == "" ? "" : " " + thousands[count]) + (res == ""  || threeConverted == "" ? "" : " ") + res;
        }
        
        count++;
    }
    return res;
}

// Code from discuss
string hundredStr(int num) {
    vector<string> arr1 = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> arr2 = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string ret;
    ret = num % 100 < 20 ? arr1[num % 100] : (arr2[(num % 100) / 10] + (num % 10 ? (" " + arr1[num%10]) : ""));
    if (num > 99)
        ret = arr1[num/100] + " Hundred" + (num % 100 ? " " + ret : "");
    return ret;
}

string numberToWords(int num) {
    string ret;
    vector<string> strarr = {"Thousand","Million","Billion"};
    ret = hundredStr(num % 1000);
    for(int i = 0; i < 3; i++){
        num /= 1000;
        ret = num % 1000 ? (hundredStr(num % 1000) + " " + strarr[i] + " " + ret) : ret;
    }
    while(ret.back() == ' ')
        ret.pop_back();
    return ret.empty() ? "Zero" : ret;
}

int main(int argc, const char * argv[]) {
    cout<<numberToWords(1000)<<endl;
    cout<<numberToWords(1234567)<<endl;
    cout<<numberToWords(1234567891)<<endl;
    return 0;
}
