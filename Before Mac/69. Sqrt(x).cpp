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
���ֵ�˼·
ע�⣬һ��������mid*mid<x���жϣ���Ϊ�ܿ���������ó����Ͳ������
loҪ��0��ʼ������lo+hiҲ�������

һ��Ҫע��mid�Ķ����if�ж�����Ƿ�ᵼ����ѭ��
���while��������hi-lo>1���ǳ�����lo<hi����ô����x=4,lo=2,hi=3����mid=(lo+hi)/2��lo=mid����ѭ��
���mid=(lo+hi)/2+1������lo=2,hi=3����ômid��hi=mid����ѭ��
��һ�ַ�ʽû���⣺
while(hi>lo){
	mid=(lo+hi)/2;
	if(x/mid<mid)
		hi=mid;
	else
		lo=mid+1;
}
return hi-1;
�������˼·���ǣ���lo��һ�㣬��֤hi�������Ӷ��˳�whileѭ������󷵻ص�ʱ���һ 
*/ 
