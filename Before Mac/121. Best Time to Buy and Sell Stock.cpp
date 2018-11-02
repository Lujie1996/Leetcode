#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int maxProfit(vector<int>& prices){
	int size=prices.size(), res=0, minPrice=INT_MAX;
	for(int i=0;i<size;i++){
		minPrice=min(minPrice,prices[i]);	//记录当前位置以前的最小值 
		res=max(res,prices[i]-minPrice);
	}
	return res;
}
int main(){
	int num[]={7, 1, 5, 3, 6, 4};
	vector<int> prices(num,num+6);
	cout<<maxProfit(prices)<<endl;
	return 0;
}
