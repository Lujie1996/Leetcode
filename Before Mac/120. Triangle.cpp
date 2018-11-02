#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>>& triangle){
	int i,j;
	for(i=0;i<triangle.size();i++){
		for(j=0;j<triangle[i].size();j++){
			cout<<triangle[i][j]<<" ";
		}
		cout<<endl;
	}
}
int minimumTotal(vector<vector<int>>& triangle){
	int minPath=INT_MAX;
	int i,j;
	for(i=1;i<triangle.size();i++){
		triangle[i][0]=triangle[i][0]+triangle[i-1][0];
		for(j=1;j<triangle[i].size()-1;j++){
			minPath=min(triangle[i-1][j],triangle[i-1][j-1]);
			triangle[i][j]=minPath+triangle[i][j];
		}
		triangle[i][j]+=triangle[i-1][j-1];
	}
	int row_no=triangle.size()-1;
	minPath=INT_MAX;
	for(i=0;i<triangle[row_no].size();i++)
		minPath=min(minPath,triangle[row_no][i]);
	return minPath;
}
int main(){
	int row_no;
	cin>>row_no;
	vector<vector<int>> triangle;
	for(int i=0;i<row_no;i++){
		vector<int> tmp(i+1,0);
		for(int j=0;j<=i;j++){
			cin>>tmp[j];
		}
		triangle.push_back(tmp);
	}
	cout<<minimumTotal(triangle)<<endl;
	return 0;
}
