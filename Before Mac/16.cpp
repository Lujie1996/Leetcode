#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int threeSum(vector<int>& nums,int target)
{
	vector< vector<int> > ans;
	if(nums.size()<3)
		return 0;
	vector<int> tmp=nums;
	sort(tmp.begin(),tmp.end());
	int k,i,j,sum;
	k=0;
	int min=999999;
	int s;
	while(k<tmp.size()-2)
	{
		i=k+1;
		j=tmp.size()-1;
		while(i<j)
		{
			sum=tmp[i]+tmp[j]+tmp[k];
			if(sum==target)
				return sum;
			else if(sum>target)
			{
				if(abs(target-sum)<min)
				{
					min=abs(target-sum);
					s=sum;
				}
				j--;
				while(i<j&&tmp[j]==tmp[j+1])
					j--;
			}
			else
			{
				if(abs(target-sum)<min)
				{
					min=abs(target-sum);
					s=sum;
				}
				i++;
				while(i<j&&tmp[i]==tmp[i-1])
					i++;
			}
		}
		k++;
		while(k<tmp.size()-2&&tmp[k]==tmp[k-1])
				k++;
	}
	return s;
}
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(-1);
	nums.push_back(-1);
	nums.push_back(3);
	cout<<threeSum(nums,-1)<<endl;
	return 0;
}
