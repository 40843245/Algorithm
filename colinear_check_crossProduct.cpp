#include <iostream>
#include <string>
#include <cmath>
#include <climits>

#define eps (0.0001)
using namespace std;

float getDet(int a,int b,int c,int d);

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
	float getCrossProduct(Point p2);
	Point operator - (Point p2);
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
Point Point::operator - (Point p2)
{
	Point tempPoint(this->x-p2.x,this->y-p2.y);
	return tempPoint;
}
bool Point::isColinear(Point p2,Point p3)
{
	Point p1(this->x,this->y);
	Point p4=p2-p1;
	float d1=p4.getCrossProduct(p3-p1);
	return abs(d1)<=eps?true:false;
}
float Point::getCrossProduct(Point p2)
{
	float result=getDet(this->x,p2.x,this->y,p2.y);
	return result;
}

float getDet(int a,int b,int c,int d)
{
	return (float)(a*d-b*c);
}
int main()
{
	Point p1(2,3),p2(2,3),p3(5,4);
	bool isCol=p1.isColinear(p2,p3);
	cout<<"isCol?"<<isCol<<endl;
	return 0;
}
