#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int>& nums){
	int lo,mid,hi;
	lo=0;
	hi=nums.size()-1;
	nums.push_back(nums[hi]-1);
	while(hi-lo>1){
		mid=lo+(hi-lo)/2;
		if(nums[mid]<nums[mid+1]){
			lo=mid;
		}
		else
			hi=mid;
	}
	return nums[lo]>nums[hi]?lo:hi;
}
int main(){
	int t[]={1,2,1};
	//int t[]={1,2,3,4,5,6,7,8,9};
	vector<int> nums(t,t+3);
	cout<<findPeakElement(nums)<<endl;
	return 0;
}
