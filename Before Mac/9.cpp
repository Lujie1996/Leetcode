#include <iostream>
using namespace std;

// Another way is to get the right half of x(presented as sum) ,
// and compare sum with the left half
bool isPalindrome(int x) {
    if(x < 0 || (x != 0 && x % 10 == 0))
        return false;
    int sum = 0;
    while (x > sum)
    {
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
}

int isPalindrome(int x)
{
	if(x<0)
		return 0;
	if(x<10)
		return 1;
	int digit,tmp,pow;
	tmp=x;
	digit=0;
	pow=1;
	while(tmp>9)
	{
		tmp /= 10;
		pow *= pow;
		digit++;
	}
	digit++;
	for(int i=0;i<digit/2;i++)
	{
		if(x/pow!=x%10)
			return 0;
		else
		{
			x=x-x/pow*pow; //2321
			x=x/10; //232
            pow=pow/100; //pow 10000 -> 100
		}
	}
	return 1;
}
int main()
{
	int x;
	while(cin>>x)
		cout<<isPalindrome(x)<<endl;
	return 0;
} 
