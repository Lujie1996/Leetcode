#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	int d='1'-1,x,tmp,i,pow,j,length;
	int result=0;
	char s[20];
	cin>>x; 
	if(x>0)
	{
		i=0;
		while(x!=0)
		{
			s[i++]=x%10+d;
			x=x/10;
		}
		length=i-1;
		s[i]='\0';
		for(i=0;s[i]!='\0';i++)
		{
			pow=1;
			for(j=0;j<i;j++)
				pow=10*pow;
			tmp=pow*(s[length-i]-d);
			if(tmp/pow!=s[length-i]-d)
			{
				cout<<0<<endl;
				return 0;
			}
			if(tmp+result<0)
			{
				cout<<0<<endl;
				return 0;
			}
			result=result+tmp;
		}
	}
	else if(x<0)
	{
		x=-x;
		i=0;
		while(x!=0)
		{
			s[i++]=x%10+d;
			x=x/10;
		}
		length=i-1;
		s[i]='\0';
		for(i=0;s[i]!='\0';i++)
		{
			pow=1;
			for(j=0;j<i;j++)
				pow=10*pow;
			tmp=pow*(s[length-i]-d);
			if(tmp/pow!=s[length-i]-d)
			{
				cout<<0<<endl;
				return 0;
			}
			if(tmp+result<0)
			{
				cout<<0<<endl;
				return 0;
			}
			result=result+tmp;
		}
		result=-result;
	}
	else
		result=0;
	cout<<result<<endl;
	return 0;
}
