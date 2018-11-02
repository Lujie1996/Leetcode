#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s="PAYPALISHIRING";
	string result;
	int n=4;
	int i=0,j=0;
	if(n==1)
		cout<<s<<endl; 
	while(j<s.length())//第一行 
	{
		result.push_back(s[j]);
		j+=2*n-2;
	}
	i=1;
	while(i!=n-1)//中间行 
	{
		j=i;
		for(j;j<s.length();j+=2*n-2)
		{
			result.push_back(s[j]);
			if(j+2*n-2-2*i<s.length())
				result.push_back(s[j+2*n-2-2*i]); 
		}
		i++;
	}
	j=i;
	while(j<s.length())//最后一行 
	{
		result.push_back(s[j]);
		j+=2*n-2;
	}
	cout<<result<<endl;
	return 0;
}
