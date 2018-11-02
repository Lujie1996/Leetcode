#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid){
	int m=grid.size();
	int n=grid[0].size();
	int i,j;
 	vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));//初始化为INT_MAX 
	dp[0][1]=0;//不可或缺，在padding都是INT_MAX的情况下保证dp[1][1]的正确性 
 	for(i=1;i<m+1;i++){
 		for(j=1;j<n+1;j++){
 			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];//注意最后加grid[i-1][j-1]而不是dp[i][j] 
		}
	}
	return dp[m][n];
}
int main(){
	vector<vector<int>> grid;
	vector<int> t;
	t.push_back(1);
	t.push_back(3);
	t.push_back(1);
	grid.push_back(t);
	t[1]=5;
	grid.push_back(t);
	t[0]=4;
	t[1]=2;
	grid.push_back(t);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<minPathSum(grid)<<endl;
	return 0;
}

