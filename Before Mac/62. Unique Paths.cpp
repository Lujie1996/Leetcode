#include <iostream>
using namespace std;
int uniquePaths(int m,int n){
	//walk downwards: (m-1) times, rightwards: (n-1) times, ans = C(n-1)(m+n-2)
	//(m+n-2)!/(n-1)!*(m-1)!
	//这种方法虽然简单，但是阶乘计算可能溢出，下面是DP的方法
	int dp[100][100],i,j;
	for(i=0;i<m;i++)
		dp[i][0]=1;
	for(j=0;j<n;j++)
		dp[0][j]=1;
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
}
int main(){
	cout<<uniquePaths(3,4)<<endl;
	return 0;
}
