#include <iostream>
#include <vector>
using namespace std;
int myAtoi(string str) {
	int i,mark,t=0,j=0,k;
	vector<int> num;
	int max = 0x7fffffff;  
    int min = 0x80000000;
	for(i=0;;i++)
	{
		if(str[i]>=48&&str[i]<=57||str[i]==43||str[i]==45)//43 for +
		{
			if(str[i]==45&&str[i+1]>=48&&str[i+1]<=57)
			{
				t=1;//to mark that the number is negative
				continue;
			}	
			if(str[i]==43&&str[i+1]>=48&&str[i+1]<=57)
				continue;
			while(str[i]>=48&&str[i]<=57)
				num.push_back(str[i++]-48);
			j=num.size();
			if(j>12)
	           {
	               if(t==1)
		                return min;
		            else
		                return max;
	           }
			j--;
	        int result=0;
	        double tmp,pow;
	        for(i=0;i<=j;i++)
	        {
		        pow=1;
		        for(k=0;k<i;k++)
			    pow=pow*10;
		        tmp=pow*num[j-i];
		        if(tmp+result>2147483647)//32位编译器中，double占8字节，int占4字节，用double存储来判断溢出是可行的 
		        {
		            if(t==1)
		                return min;
		            else
		                return max;
		        }
		        else
			        result+=tmp;
	        }
	        if(t==1)
		        result=-result;
	        return result;
		}
		else if(str[i]==' ')
			continue;
		else
			return 0;		
	}
    }
int main(){
	string str="2147483648";
	cout<<myAtoi(str);
	return 0;
}

