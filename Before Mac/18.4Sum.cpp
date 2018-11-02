#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target) 
{
	int i,j,t,left,right;
	vector<vector<int> > result;
	vector<int> item; 
	if(nums.size()<4)
		return result;
	sort(nums.begin(),nums.end());//-2 -1 -1 0 0 2
	i=0;
	while(i<nums.size()-3)
	{
		j=i+1;
		while(j<nums.size()-2)
		{
			t=target-nums[i]-nums[j];
			left=j+1;
			right=nums.size()-1;
			while(left!=right)
			{
				int sum=nums[left]+nums[right];
				if(sum==t)
				{
					item.push_back(nums[i]);
					item.push_back(nums[j]);
					item.push_back(nums[left]);
					item.push_back(nums[right]);
					result.push_back(item);
					item.clear();		
					right--;
					while(nums[right+1]==nums[right]&&right!=left)
						right--;
				}
				else if(sum<t)
				{
					left++;
					while(nums[left]==nums[left-1]&&left!=right)
						left++;
				}		
				else if(sum>t)
				{
					right--;
					while(nums[right]==nums[right+1]&&right!=left)
						right--;
				}			
			}
			j++;
			while(j<nums.size()-2&&nums[j]==nums[j-1])
				j++; 
		}
		i++;
		while(i<nums.size()-3&&nums[i]==nums[i-1])
			i++; 
	} 
	return result;  
}
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(-2);
	nums.push_back(4);
	vector<vector<int> > result=fourSum(nums,0);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
