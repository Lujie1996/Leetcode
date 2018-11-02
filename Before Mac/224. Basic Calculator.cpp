#include <iostream>
#include <string>
#include <stack>
using namespace std; 
int calculate(string s){
	int res=0,sign=1,len=s.length();
	stack<int> st;
	for(int i=0;i<len;i++){
		char c=s[i];
		if(c>='0'){
			int num=0;
			while(i<len&&s[i]>='0'){
				num=num*10+s[i++]-'0';
			}
			res+=num*sign;
			i--;
		}
		else if(c=='+'){
			sign=1;
		}
		else if(c=='-'){
			sign=-1;
		}
		else if(c=='('){
			st.push(res);
			st.push(sign);
			res=0;
			sign=1;
		}
		else if(c==')'){
			res*=st.top();
			st.pop();
			res+=st.top();
			st.pop();
		}
	} 
	return res;
}
int main()
{
	cout<<calculate("5-(1+2)")<<endl;
	return 0;
}
/*
以"5-(1+2)"为例，计算1+2时就是:
res+=sign*num+sign*num
res+=1*1+1*2 
遇到左括号‘(’时，将res和sign呀栈
遇到右括号‘)’时，当前的res就是从对应左括号到该右括号内算式的结果，res*=出栈的sign，再+=出栈的前面的结果 
*/
