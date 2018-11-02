#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int>& nums,int left,int right)
{
	while(left<right)
	{
		swap(nums[left],nums[right]);
		left++;
		right--;
	}
}
void rotate(vector<int>& nums, int k)
{
	int l=nums.size();
	k=k%l;//有可能k比nums.size()还要大，所以取模来应对这种问题 
	reverse(nums,0,l-k-1);
	reverse(nums,l-k,l-1);
	reverse(nums,0,l-1);	
}
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	rotate(nums,2);
	int i=0;
	while(i<nums.size())
	{
		cout<<nums[i]<<endl;
		i++;
	}
	return 0;
}

