#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector< vector<int> > threeSum(vector<int>& nums)
{
	vector< vector<int> > ans;
	if(nums.size()<3)
		return ans;
	vector<int> tmp=nums;
	sort(tmp.begin(),tmp.end());
	int k,i,j,sum;
	k=0;
	while(k<tmp.size()-2)
	{
		i=k+1;
		j=tmp.size()-1;
		if(tmp[k]>0)
			return ans;
		if(tmp[j]<0)
			return ans; 
		while(i<j)
		{
			sum=tmp[i]+tmp[j]+tmp[k];
			if(sum==0)
			{
				vector<int> t;
				t.push_back(tmp[k]);
				t.push_back(tmp[i]);
				t.push_back(tmp[j]);
				ans.push_back(t);
				i++;
				while(i<j&&tmp[i]==tmp[i-1])
					i++;
				j--;
				while(i<j&&tmp[j]==tmp[j+1])
					j--;		
			}
			else if(sum>0)
			{
				j--;
				while(i<j&&tmp[j]==tmp[j+1])
					j--;
			}
			else
			{
				i++;
				while(i<j&&tmp[i]==tmp[i-1])
					i++;
			}
		}
		k++;
		while(k<tmp.size()-2&&tmp[k]==tmp[k-1])
				k++;
	}
	return ans;
}
int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);
	vector< vector<int> > ans=threeSum(nums);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<3;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	cout<<ans.size()<<endl;
	return 0;
}
