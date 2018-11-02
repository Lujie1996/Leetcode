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
��"5-(1+2)"Ϊ��������1+2ʱ����:
res+=sign*num+sign*num
res+=1*1+1*2 
���������š�(��ʱ����res��signѽջ
���������š�)��ʱ����ǰ��res���ǴӶ�Ӧ�����ŵ�������������ʽ�Ľ����res*=��ջ��sign����+=��ջ��ǰ��Ľ�� 
*/
