#include <iostream>
#include <map>
#include <vector>
//本题用map。map用平衡二叉树的方法实现了两类元素的一一对应。 
using namespace std;
bool containsDuplicate(vector<int>& nums)
{
	map<int,int> intmap;
	int i=0,size=nums.size();
	while(i<size)
	{
		if(intmap.count(nums[i]))//如果nums[i]在map中出现过，则map.count(nums[i])=1，没出现过则为0 
			return true;
		else
			intmap.insert(pair<int,int>(nums[i],i));//将未出现过的数字nums[i]插入，至于后面的数字就无所谓了 
		i++;
	}
	return false;
}
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(9);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	if(containsDuplicate(nums))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
