#include <iostream>
#include <string>
#include <stack>
using namespace std;
//¿®∫≈∆•≈‰ 
bool isValid(string s)
{
	stack<char> stk;
	int i=0,length;
	length=s.length();
	if(length==1)
		return 0;
	while(i<length)
	{
		if(s[i]=='{'||s[i]=='['||s[i]=='(')
			stk.push(s[i]);
		else if(s[i]==')')
		{
			if(!stk.empty()&&stk.top()=='(')
				stk.pop();	
			else
				return 0;
		}
		else if(s[i]==']')
		{
			if(!stk.empty()&&stk.top()=='[')
				stk.pop();	
			else
				return 0;
		}
		else if(s[i]=='}')
		{
			if(!stk.empty()&&stk.top()=='{')
				stk.pop();	
			else
				return 0;
		}
		i++;
	}
	if(!stk.empty())
		return 0;
	else
		return 1;
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(isValid(s))
			cout<<"valid"<<endl;
		else
			cout<<"invalid"<<endl;
	}
	return 0;
}
