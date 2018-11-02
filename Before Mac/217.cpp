#include <iostream>
#include <map>
#include <vector>
//������map��map��ƽ��������ķ���ʵ��������Ԫ�ص�һһ��Ӧ�� 
using namespace std;
bool containsDuplicate(vector<int>& nums)
{
	map<int,int> intmap;
	int i=0,size=nums.size();
	while(i<size)
	{
		if(intmap.count(nums[i]))//���nums[i]��map�г��ֹ�����map.count(nums[i])=1��û���ֹ���Ϊ0 
			return true;
		else
			intmap.insert(pair<int,int>(nums[i],i));//��δ���ֹ�������nums[i]���룬���ں�������־�����ν�� 
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
