#include <iostream>
#include <vector>
using namespace std;
int biSearch(vector<int> nums, int target, int lo, int hi){
	int mid=0;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(target>nums[mid])
			lo=mid+1;
		else if(target==nums[mid])
			return true;
		else
			hi=mid-1;
	}
	return false;
}
bool search(vector<int>& nums, int target) {
	if(nums.size()==0)
		return false;
	int lo=0,hi=nums.size()-1,mid=0;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(nums[mid]==target)
			return true;
		if(nums[mid]>nums[lo]){	//left half is ordered
			//必须是大于等于，否则长度为2的串就无法正确归类。
			//例：当[3,1],target=3时，应该在左半部分查找。 
			if(target>=nums[lo]&&target<=nums[mid])
				return biSearch(nums,target,lo,mid-1);
			else
				lo=mid+1;
		}
		else if(nums[mid]==nums[lo]){
			lo++;		//Worst case: O(n)
		}
		else{					//right half is ordered
			if(target>=nums[mid]&&target<=nums[hi])
				return biSearch(nums,target,mid+1,hi);
			else
				hi=mid-1;
		}	
	}
	if(nums[lo]!=target)
		return false;
	else
		return true;
}
int main(){
	int vec[]={1,1,3,1};
	vector<int> nums(vec,vec+4);
	int x;
	while(cin>>x)
		cout<<search(nums,x)<<endl;
	return 0;
}

