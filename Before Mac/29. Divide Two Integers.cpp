#include <iostream>
#include <math.h>
using namespace std;
int divide(int dividend, int divisor){
	if (!divisor||(dividend==INT_MIN&&divisor==-1))
        return INT_MAX;
    int sign;
    if(dividend>0&&divisor>0||dividend<0&&divisor<0)
    	sign=1;
    else
    	sign=-1;
    long long remain=llabs(dividend); //��long long��abs������abs()��abs(INT_MIN)=0 
    long long dvs=llabs(divisor);
    long long ans=0;
    long long count,tmp,next_tmp;
    while(remain>=dvs){
    	tmp=dvs;
    	count=1;
    	next_tmp=tmp<<1;
    	while(remain>next_tmp){
    		tmp<<=1;
    		count<<=1;
    		next_tmp=tmp<<1;
		}	
		remain-=tmp;
		ans+=count;
	}
	return sign==1?ans:-ans;
}
int main(){
	cout<<divide(-2147483648,1)<<endl;
	return 0;
}
/*
����˼����������Ƶ�λ���������г�2�ͳ�2������������Ҫһ��count������ 
*/
