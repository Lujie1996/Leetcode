#include <iostream>
using namespace std;
double myPow(double x, int n) {
	if(n==0)
		return 1.0;
	if(n<0){
		if(n==INT_MIN)
			return 1.0/(myPow(x,INT_MAX)*x); //ע�⣬32bit�����int��ΧΪ2^32-1 ~ -(2^32), ���Զ���INT_MIN��INT_MAXҪ�������� 
		else
			return 1.0/myPow(x,-n);
	}
	else{
		double ans=1.0;
		while(n>0){
			if(n&1==1){
				ans*=x;
			}
			x*=x;
			n=n>>1;
		}
		//��������Ŀ�n����������1��λ��iλ������ans���Զ�Ӧ��x��(2^i)�η� 
		return ans;
	}
}
int main(){
	int x=2.0;
	for(int i=0;i<=10;i++){
		cout<<"i="<<i<<" res: "<<myPow(x,-i)<<" "<<myPow(x,i)<<endl;
	}
	return 0;
}
