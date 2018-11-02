#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
	if(nums.size()==0)
		return 0;
	int i,counter=1,j;
	for(i=1;i<nums.size();i++)
	{
		if(nums[i-1]!=nums[i])
			counter++;
	}
	i=0;j=0;
	while(j<nums.size())
	{
		if(nums[i]==nums[j])
		{
			while(nums[j]==nums[i])
				j++;
			i++;
			nums[i]=nums[j];
		}
	}
	nums.erase(nums.begin()+i,nums.end());
	return counter;
} 
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	cout<<removeDuplicates(nums)<<endl;
	for(int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	return 0;
}
