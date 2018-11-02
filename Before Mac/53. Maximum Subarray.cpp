#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums){
	int max,sum,i;
	sum=0;
	max=INT_MIN;
	for(i=0;i<nums.size();i++){
		sum+=nums[i];
		if(sum<0){
			sum=0;
		}
		else{
			if(max<sum)
				max=sum;
		}
	}
	if(max>=0)
		return max;
	//下面考虑数组全部是负数的情况 
	max=nums[0];
	for(i=1;i<nums.size();i++)
		if(nums[i]>max)
			max=nums[i];
	return max;
}
int main(){
	//int a[]={-2,1,-3,4,-1,2,1,-5};
	int a[]={-2,-1,-3,-4,-1,-2,-1,-5};
	vector<int> nums(a,a+8);
	cout<<maxSubArray(nums)<<endl;
	return 0;
}
