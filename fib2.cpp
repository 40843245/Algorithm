#include <iostream>
using namespace std;
#define NUM 50
int fib[NUM];
void build()
{
	fib[0]=0;
	fib[1]=1;
	fib[2]=2;
	for(int i=3;i<NUM;i++)
	{
		fib[i]=fib[i-1]+fib[i-2]+fib[i-3];
	}
}
int F(int n)
{
	return fib[n];
}
int main()
{
	build();
	cout<<"F(10)="<<F(10)<<endl;
	return 0;
}
