#include <iostream>
using namespace std;
double myPow(double x, int n) {
	if(n==0)
		return 1.0;
	if(n<0){
		if(n==INT_MIN)
			return 1.0/(myPow(x,INT_MAX)*x); //注意，32bit计算机int范围为2^32-1 ~ -(2^32), 所以对于INT_MIN和INT_MAX要单独处理 
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
		//从右往左的看n，遇到等于1的位（i位）就让ans乘以对应的x的(2^i)次方 
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
