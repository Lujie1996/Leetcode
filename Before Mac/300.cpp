#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums)
{
	if(nums.size()==0)
		return 0;
	vector<int> DP(nums.size());
	int i,j;
	DP[0]=1;
	int m=1;
	for(i=1;i<nums.size();i++)
	{
		DP[i]=1;
		for(j=0;j<i;j++)
		{
			if(nums[i]>nums[j])
				DP[i]=max(DP[i],DP[j]+1);	
		}
		m=max(m,DP[i]);	
	}
	return m;
}
int main()
{
	//10, 9, 2, 5, 3, 7, 101, 18
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(4);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(6);
	cout<<lengthOfLIS(nums)<<endl;
	return 0;
}
