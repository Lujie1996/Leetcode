#include <iostream>
#include <vector>
#include <map>
using namespace std;
int majorityElement(vector<int>& nums)
{
 	map<int,int> cnt; //map������ļ����������ر���� 
 	map<int,int>::iterator it;
 	for(int i=0;i<nums.size();i++)
 	{
 		it=cnt.find(nums[i]);
 		if(it==cnt.end())
 			cnt.insert(pair<int,int>(nums[i],1));//ע��insert()����������ĸ�ʽ 
 		else
 			it->second++;
 	}
 	it=cnt.begin();
 	int result;
 	while(it!=cnt.end())
 	{
 		if(it->second>nums.size()/2)
 		{
 			result=it->first;
 			return result;
 		}
 		it++;
 	}
}
int main()
{
 	vector<int> nums;
 	nums.push_back(1);
 	nums.push_back(1);
 	nums.push_back(1);
 	nums.push_back(1);
 	nums.push_back(3);
 	nums.push_back(3);
 	nums.push_back(3);
 	cout<<majorityElement(nums);
 	return 0;
}
