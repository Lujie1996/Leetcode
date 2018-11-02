#include <iostream>
#include <string>
using namespace std;
string countandsay(string str){
	int i,j;
	j=0;
	string s;
	int D='0'-0;
	while(j<str.size()) 
	{
		char a=str[j];
		i=0;
		while(a==str[j+i])
			i++;
		j=j+i;
		s.push_back(i+D);
		s.push_back(a);
	}
	return s;	
}
string countAndSay(int n) {
	string str="1";
	int i=1;
	while(i<n)
	{
		str=countandsay(str);
		i++;
	}
	return str;
}

int main()
{
	int n;
	while(cin>>n)
		cout<<countAndSay(n)<<endl;
	return 0;
}
