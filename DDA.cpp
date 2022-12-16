#include <iostream>
#include <algorithm>
using namespace std;

void DDA(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int step=max(abs(dx),abs(dy));
	float xinc=dx/step;
	float yinc=dy/step;
	for(int k=1;k<=step;k++)
	{
		cout<<"x="<<x1<<",y="<<y1<<endl;
		x1=x1+xinc;
		y1=y1+yinc;
	}
	return;
}
int main()
{
	int point[4]={1,2,1,8};
	DDA(point[0],point[1],point[2],point[3]);
	return 0;
}
