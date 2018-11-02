#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val)
{
	int i=0,count=0,size;
	size=nums.size();
	while(i<nums.size()) 
	{
		if(nums[i]==val)
		{
			nums.erase(nums.begin()+i);
			count++;
			if(nums.size()==0)
				return size-count;
		}
		else
			i++;
	}
	return size-count;
} 
int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	cout<<removeElement(nums,2)<<endl;
	for(int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	return 0;
}
