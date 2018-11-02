#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums){
	int lo,hi,sum,minLen,len;
	lo=0;
	hi=0;
	sum=0;
	minLen=nums.size();
	for(hi=0;hi<nums.size();hi++){
		sum+=nums[hi];
		while(sum-nums[lo]>=s){
			sum-=nums[lo];
			lo++;	
		}
		if(sum>=s){
			minLen=min(minLen,hi-lo+1);
		}
	}
	return sum>=s?minLen:0;
}
int main(){
	int t[]={2,3,1,1,1,1,1};
	vector<int> nums(t,t+7);
	cout<<minSubArrayLen(5,nums)<<endl;;
	return 0;
}
