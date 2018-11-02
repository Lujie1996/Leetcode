#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums)
{
	int i,j,tmp;
	for(i=0;i<nums.size();i++)
	{
		if(nums[i]!=0)
			continue;
		else
		{
			j=i;
			for(j;j<nums.size();j++)
			{
				if(nums[j]==0)
					continue;
				else
				{
					tmp=nums[i];
					nums[i]=nums[j];
					nums[j]=tmp;
					break;
				}
			}
		}
	}
}
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(3);
	moveZeroes(nums);
	int i;
	for(i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	return 0;
} 
