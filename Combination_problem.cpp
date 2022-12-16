#include <iostream>
using namespace std;
#define ROW 50
#define COL 50
int combination[ROW][COL];
void build()
{
	for(int i=0;i<ROW;i++)
	{
		combination[i][0]=1;
		combination[i][i]=1;
	}
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<i;j++)
		{
			combination[i][j]=combination[i-1][j-1]+combination[i-1][j];
		}
	}
}
int C(int m,int n)
{
	return combination[m][n];
}
int main()
{
	build();
	cout<<"C(10,3)="<<C(10,3)<<endl;
	return 0;
}
