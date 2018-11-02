#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums,int k)
{
	map<int,int> intmap;
	map<int,int>::iterator iter;
	int i=0,size=nums.size();
	while(i<size)
	{
		if(intmap.count(nums[i]))
		{
			iter=intmap.find(nums[i]);
			if(i-iter->second<=k) 
				return true;
			iter->second=i;
		}
		else
			intmap.insert(pair<int,int>(nums[i],i));
		i++;
	}
	return false;
}
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(1);

	if(containsDuplicate(nums,1))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
