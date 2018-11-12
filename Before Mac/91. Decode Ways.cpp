#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int numDecodings(string s){
	if (s.empty() || (s.size() > 1 && s[0] == '0')) 
		return 0;
    vector<int> dp(s.size() + 1, 0);
    // dp[i]: number of decodings of s.substr(0,i)   (not including s[i])
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }
    return dp.back();
}
int main(){
	string s;
	while(cin>>s){
		cout<<numDecodings(s)<<endl;
	}
	return 0;
}
/*
	if str[n] is valid
	    dp[n] += dp[n - 1]
	if str[n - 1] combine str[n] is valid
	    dp[n] += dp[n - 2]
*/
