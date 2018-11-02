#include <iostream>
using namespace std;
int Count(int v)
{
	int count = 0;
	while(v)
	{
		if(v&0x01)
			count++;
		v>>=1;
	}
	return count;
}
int main()
{
	int x = 1;
	cout<<Count(x)<<endl;
	return 0;
}

