#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#define eps (0.0001)
using namespace std;
class Point
{
private:
	int x;
	int y;
public:
	
	Point(){this->x=0,this->y=0;}
	Point(int x,int y){this->x=x,this->y=y;}
	Point(const Point &p1){this->x=p1.x,this->y=p1.y;}
	bool isSamePoint(Point p2);
	float getSlope(Point p2);
	void displayPoint();
	void displaySlope(Point p2,string msg1,string msg2);
	bool isColinear(Point p2,Point p3);
};
float Point::getSlope(Point p2)
{
		if(p2.y-this->y==0)
		{
			return 0.0f;	
		}
		if(p2.x-this->x==0)
		{
			return INT_MIN;
		}
		float m=(p2.y-this->y)/(float)(p2.x-this->x);
}
void Point::displayPoint()
{
	cout<<"("<<this->x<<","<<this->y<<")";
}
bool Point::isSamePoint(Point p2)
{
	return (this->x==p2.x && this->y==p2.y);
}
void Point::displaySlope(Point p2,string msg1,string msg2)
{
	cout<<"slope of "<<msg1<<" ";
	this->displayPoint();
	cout<<" and "<<msg2<<" ";
	p2.displayPoint();	
	cout<<" is ";
	float m=this->getSlope(p2);
	if(m==INT_MIN)
	{
		cout<<"infinity";
	}else
	{
		cout<<m;
	}
	cout<<endl;
	return;
	
}
bool Point::isColinear(Point p2,Point p3)
{
	float m1_2=this->getSlope(p2);
	float m1_3=this->getSlope(p3);
	float isSame=this->isSamePoint(p2)||this->isSamePoint(p3)||p2.isSamePoint(p3);
	return (abs(m1_2-m1_3)<eps || isSame)?true:false;
}
int main()
{
	Point p1(2,3),p2(2,3),p3(5,4);
	p1.displaySlope(p2,"p1","p2");
	bool isCol=p1.isColinear(p2,p3);
	cout<<"isCol?"<<(isCol!=0?"true":"false")<<endl;
	return 0;
}
