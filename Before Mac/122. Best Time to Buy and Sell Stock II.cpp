#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int maxProfit(vector<int>& prices){
    int size=prices.size(), minPrice=INT_MAX, res=0, tmp=0;
    for(int i=0;i<size;i++){
    	minPrice=min(minPrice, prices[i]);
    	tmp=max(tmp,prices[i]-minPrice);
    	if(i+1==size||prices[i+1]<prices[i]){
    		res+=tmp;
    		tmp=0;
    		minPrice=INT_MAX;
		}
	}
	return res;
}
int main(){
//	int nums[]={5,1,4,6,2,4,9,3};
//	vector<int> prices(nums,nums+8);
	int nums[]={1,2};
	vector<int> prices(nums,nums+2);
	cout<<maxProfit(prices)<<endl;
	return 0;
} 
