#include <iostream>
using namespace std;
//int strStr(string haystack, string needle)
//{
//    if(haystack.empty()&&needle.empty()||haystack==needle)return 0;
//    if(haystack.empty()&&!needle.empty()||haystack.length()<needle.length())return -1;
//    for(int i=0;i<=haystack.length()-needle.length();i++)if(haystack.substr(i,needle.length())==needle)return i;
//    return -1;
//}

// Rabin Karp algorithm. Use hashmap. O(m+n) time complexity.
int strStr(string haystack, string needle) {
    int len1 = (int)haystack.size(), len2 = (int)needle.size();
    if (len2 == 0) {
        return 0;
    }
    unordered_map<string, int> substrIndex;
    for (int i = 0; i <= len1 - len2; i++) {
        string substr = haystack.substr(i, len2);
        if (substrIndex.find(substr) == substrIndex.end()) {
            substrIndex[substr] = i;
        }
    }
    return substrIndex.find(needle) == substrIndex.end() ? -1 : substrIndex[needle];
}
int main()
{
	string s1="whatishappiness?";
	string s2;
	while(cin>>s2)
	{
		cout<<strStr(s1,s2)<<endl;
	}
	return 0;
}
