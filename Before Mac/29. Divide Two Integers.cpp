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
    long long remain=llabs(dividend); //对long long的abs不能用abs()，abs(INT_MIN)=0 
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
核心思想就是用左移的位操作来进行乘2和除2操作，另外需要一个count来计数 
*/
