#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int minDistance(string word1, string word2){
	int len1=word1.size();
	int len2=word2.size();
	vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			if(word1[i]==word2[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else{
				dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	return len1+len2-2*dp[len1][len2];	
}
int main(){
	string word1="";
	string word2="";
	cout<<minDistance(word1,word2)<<endl;
	return 0;
}
/*
minDistance = （word1的长度 - LCS）+（word2的长度 - LCS） 
The key issue is to calculate the LCS
*/
