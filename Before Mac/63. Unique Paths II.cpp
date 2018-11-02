#include <iostream>
#include <vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	int dp[100][100],i,j,tmp,m,n;
	tmp=1;
	m=obstacleGrid.size();
	n=obstacleGrid[0].size();
	for(i=0;i<m;i++){
		if(obstacleGrid[i][0]==1)
			tmp=0;
		dp[i][0]=tmp;
	}
	tmp=1;
	for(j=0;j<n;j++){
		if(obstacleGrid[0][j]==1)
			tmp=0;
		dp[0][j]=tmp;
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(obstacleGrid[i][j]==1)
				dp[i][j]=0;
			else
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
}
int main(){
	vector<vector<int>> grid;
	vector<int> t;
	t.push_back(0);
	t.push_back(0);
	t.push_back(0);
	grid.push_back(t);
	t[1]=1;
	grid.push_back(t);
	t[1]=0;
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
	cout<<uniquePathsWithObstacles(grid)<<endl;
	return 0;
}
/*
���Ը�����dpһ��padding�Ӷ��򻯳�ʼ��
 	int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i = 1 ; i <= m ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m][n]; 
���ڼ���dp���Ǵ������Ҵ������£����ֻҪ��dp[0][1]=1����
�����к͵����ж���0�����Կ���ֱ�ӰѶԵ�һ�еĳ�ʼ�����������ѭ���� 
*/
