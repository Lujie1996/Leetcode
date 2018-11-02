#include <iostream>
using namespace std;
int romanToInt(string s)
{
	int i=0,result=0,size=s.size();
	while(i<size)
	{
		switch(s[i]){
			case 'I':result++; break;
			case 'V':result+=5; break;
			case 'X':result+=10; break;
			case 'L':result+=50; break;
			case 'C':result+=100; break;
			case 'D':result+=500; break;
			case 'M':result+=1000; break;
		}
		i++;
	}
	i=0;
	while(i<size-1)
	{
		if(s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))
			result-=2;
		else if(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))
			result-=20;
		else if(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M'))
			result-=200;
		i++;
	}
	return result;
}
int main()
{
	string s;
	while(cin>>s)
		cout<<romanToInt(s)<<endl;
	return 0;
} 
