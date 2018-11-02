#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	int n=nums.size();
	if(n<3)
		return n;
	int index=2;
	for(int i=2;i<n;i++)
	{
		if(nums[i]!=nums[index-2])
			nums[index++]=nums[i];
	}
	cout<<index<<endl;
	return 0;
}
