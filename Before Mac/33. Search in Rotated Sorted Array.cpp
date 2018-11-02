#include <iostream>
#include <vector>
using namespace std;
int biSearch(vector<int> nums, int target, int lo, int hi){
	int mid=0;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(target>nums[mid])
			lo=mid+1;
		else
			hi=mid;
	}
	if(nums[lo]==target)
		return lo;
	else
		return -1;
}
int search(vector<int>& nums, int target) {
	if(nums.size()==0)
		return -1;
	int lo=0,hi=nums.size()-1,mid=0;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(nums[mid]>=nums[lo]){	//left half is ordered
			//必须是大于等于，否则长度为2的串就无法正确归类。
			//例：当[3,1],target=3时，应该在左半部分查找。 
			if(target>=nums[lo]&&target<=nums[mid])
				return biSearch(nums,target,lo,mid);
			else
				lo=mid+1;
		}
		else{					//right half is ordered
			if(target>=nums[mid]&&target<=nums[hi])
				return biSearch(nums,target,mid,hi);
			else
				hi=mid-1;
		}	
	}
	if(nums[lo]!=target)
		return -1;
	else
		return lo;
}
int main(){
	int vec[]={4,5,6,7,8,0,1,2,3};
	vector<int> nums(vec,vec+9);
	cout<<search(nums,5)<<endl;
	return 0;
}
/*
思路：根据观察发现规律，比较mid和lo的值来判断left/right half有序
	  有序则直接用普通的二分查找，无序则缩小lo/hi继续进入这个判断过程。 
*/

/*
另外一种不需要单独写二分搜索的代码：
 int start = 0, end = nums.length - 1;
    while (start < end) {
        int mid = (start + end) / 2;
        if (nums[mid] > nums[end]) {  // eg. 3,4,5,6,1,2 左半部分有序 
            if (target > nums[mid] || target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid; //直接在有序的一侧查找 
            }
        } else {  // eg. 5,6,1,2,3,4
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
    }
    if (start == end && target != nums[start]) return -1;
    return start; 
*/ 

