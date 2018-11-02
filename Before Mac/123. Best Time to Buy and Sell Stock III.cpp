#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int maxProfit(vector<int>& prices){
	int size=prices.size(), profit=0, minPrice=INT_MAX;
	vector<int> profits;
	for(int i=0;i<size;i++){
		minPrice=min(minPrice, prices[i]);
		profit=max(profit,prices[i]-minPrice);
		if(i+1==size||prices[i+1]<prices[i]){
			minPrice=INT_MAX;
			profits.push_back(profit);
			profit=0;
		}
	}
	int maxProfit=0, index, res=0;
	for(int i=0;i<profits.size();i++){
		if(profits[i]>maxProfit){
			index=i;
			maxProfit=profits[i];
		}
	}
	res+=maxProfit;
	maxProfit=0;
	if(index>=0&&index<profits.size()){
		profits[index]=0;
	}
	for(int i=0;i<profits.size();i++){
		maxProfit=max(maxProfit,profits[i]);
	}
	res+=maxProfit;
	return res;
}
int main(){
	int nums[]={1,2,4,2,5,8,3,8};
	vector<int> prices(nums,nums+8);
	cout<<maxProfit(prices)<<endl;
	return 0;
}
