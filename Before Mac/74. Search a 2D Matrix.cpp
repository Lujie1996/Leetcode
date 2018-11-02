#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int lo,hi,mid,row_size,col_size;
    if(matrix.size()==0)
    	return false;
    if(matrix[0].size()==0)
    	return false; 
	//两个if判断不能写在一起，因为||判断非短路 
    row_size=matrix.size()-1;
    col_size=matrix[0].size()-1;//在完成上面的判断之后才能计算col_size，否则指针错误 
    lo=0;
    hi=row_size;
    while(lo<hi){
    	mid=(lo+hi)/2;
    	if(target>matrix[mid][col_size])
    		lo=mid+1;
    	else
    		hi=mid;
	}
	int row=lo;
	lo=0;
	hi=col_size;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(matrix[row][mid]<target)
			lo=mid+1;
		else
			hi=mid;
	}
	if(matrix[row][lo]==target)
		return true;
	else
		return false;
}
int main(){
	vector<vector<int>> x;
	int r1[]={1,3,5,7};
	int r2[]={10,12,15,17};
	int r3[]={21,25,26,28};
	int r4[]={30,35,36,39};
	vector<int> row1(r1,r1+4);
	vector<int> row2(r2,r2+4);
	vector<int> row3(r3,r3+4);
	vector<int> row4(r4,r4+4);
	x.push_back(row1);
	x.push_back(row2);
	x.push_back(row3);
	x.push_back(row4);
//	vector<int> row1;
//	vector<int> row2;
//	row1.push_back(1);
//	row2.push_back(3);
//	x.push_back(row1);
//	x.push_back(row2);
	int target;
	while(cin>>target)
		cout<<searchMatrix(x,target)<<endl;
	return 0;
}
