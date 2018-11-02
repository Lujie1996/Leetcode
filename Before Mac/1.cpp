#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> tmp=nums;
	sort(tmp.begin(),tmp.end());
	int i,j,sum,a,b,k;
	i=0;
	j=tmp.size()-1;
	while(i!=j)
	{
		sum=tmp[i]+tmp[j];
		if(sum==target)
			break; 
		if(sum<target)
			i++;
		else
			j--;
	}
	k=0;
	while(nums[k]!=tmp[i])
		k++;
	a=k;
	k=0;
	while(k<nums.size())
	{
		if(nums[k]==tmp[j])
		{
			if(k==a)
				k++;
			else
				break;
		}
		else
			k++;
	}
	b=k;
	vector<int> ans;
	ans.push_back(a);
	ans.push_back(b);
	return ans;
} 
int main()
{
	vector<int> nums,ans;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(0);
	ans=twoSum(nums,0);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
} 
