#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	if(strs.empty())
		return "";
	string result,tmp;
	int i,j,size;
	i=0;
	j=0;
	size=strs.size();
	sort(strs.begin(),strs.end());
	tmp=strs[0];
	while(i<tmp.length())
	{
		j=1;
		while(j<size)
		{
			if(tmp[i]==strs[j][i])
				j++;
			else
				break;
		}
		if(j==size)
			i++;
		else
			break;
	}
	return strs[0].substr(0,i);
}
int main()
{
	vector<string> strs;
	int i;
	string tmp;
	i=0;
	while(i<3)
	{
		i++;
		cin>>tmp;
		strs.push_back(tmp);
	}
	cout<<longestCommonPrefix(strs)<<endl;
	return 0;
}
