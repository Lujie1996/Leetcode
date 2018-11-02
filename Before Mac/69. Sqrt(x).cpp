#include <iostream>
#include <math.h>
using namespace std;
int mySqrt(int x){
	int lo,hi,mid;
	lo=0;
	hi=x;
	while(hi-lo>1){
		mid=(lo+hi)/2;
		if(x/mid<mid)
			hi=mid;
		else
			lo=mid;
	}
	if(x==hi*hi)
		return hi;
	else
		return lo;
}
int main(){
	int x;
	while(cin>>x)
		cout<<mySqrt(x)<<" "<<sqrt(x)<<endl;
	return 0;
}

/*
二分的思路
注意，一定不能用mid*mid<x来判断，因为很可能溢出，用除法就不会溢出
lo要从0开始，否则lo+hi也可能溢出

一定要注意mid的定义和if判断语句是否会导致死循环
如果while条件不是hi-lo>1而是常见的lo<hi，那么考虑x=4,lo=2,hi=3，则mid=(lo+hi)/2和lo=mid会死循环
如果mid=(lo+hi)/2+1，考虑lo=2,hi=3，那么mid和hi=mid会死循环
有一种方式没问题：
while(hi>lo){
	mid=(lo+hi)/2;
	if(x/mid<mid)
		hi=mid;
	else
		lo=mid+1;
}
return hi-1;
代码设计思路就是：让lo大一点，保证hi不动，从而退出while循环，最后返回的时候减一 
*/ 
