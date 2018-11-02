#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int p = m+n, p1 = m-1, p2 = n-1;
    while(--p>=0)
    {
    	if(p1<0||(p2>=0&&nums2[p2]>nums1[p1]))
    		nums1[p]=nums2[p2--];
    	else
    		nums1[p]=nums1[p1--];
    	
    }
} 
int main()
{
	vector<int> nums1,nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums2.push_back(4);
	nums2.push_back(5);
	nums2.push_back(6);
	//nums2.push_back(1); 
	int i;
	merge(nums1,3,nums2,3);
	for(i=0;i<nums1.size();i++)
		cout<<nums1[i]<<" ";
	return 0;
}
