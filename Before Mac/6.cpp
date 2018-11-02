#include<iostream>
#include<string>
using namespace std;
int main()
{
	int nRows=4;
	string s="Paypalishiring";
	string result;  
    if (nRows < 2) 
		cout<<s<<endl;
    for (int i = 0;i < nRows;++i) {  
        for (int j = i;j < s.length();j += 2 * (nRows - 1)) {  
        	result.push_back(s[j]);  
            if (i > 0 && i < nRows - 1) {  
                if (j + 2 * (nRows - i - 1) < s.length())  
                result.push_back(s[j + 2 * (nRows - i - 1)]);  
            }  
            }  
    }  
    cout<<result<<endl; 
	return 0;
};
