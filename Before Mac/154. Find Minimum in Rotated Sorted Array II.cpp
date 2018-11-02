#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums){
	int lo,hi,mid,min;
	lo=0;
	hi=nums.size()-1;
	min=nums[0];
	while(lo<=hi){
		mid=lo+(hi-lo)/2;
		if(nums[mid]>nums[lo]){
			if(nums[lo]<min)
				min=nums[lo];
			lo=mid+1;
		}
		else if(nums[mid]<nums[lo]){
			if(nums[mid]<min)
				min=nums[mid];
			hi=mid-1;
		}	
		else{
			if(nums[lo]<min)
				min=nums[lo];
			lo++;
		}
	}
	return min;
}
int main(){
	int t[]={4,5,6,0,1,1,2};
	vector<int> nums(t,t+7);
	cout<<findMin(nums)<<endl;
	return 0;
}
