#include <iostream>
using namespace std;
int lengthOfLastWord(string s) {
   int i,l;
   l=0;
   i=s.size()-1;
   while(i>=0)
   {
   		if(s[i]==' ')
   		{
   			if(l!=0)
   				break;
   			i--;
   			l=0;
   		}
   		else
   		{
   			i--;
   			l++;
   		}
   } 
   if(l==0)
	return 0;
   else
	return l--;
}
int main()
{
	string s;
	while(cin>>s)
	{
		cout<<lengthOfLastWord(s)<<endl;
	}
	return 0;
}
