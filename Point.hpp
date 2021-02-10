#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point;

std::ostream& operator<< (std::ostream& o, const Point & p);

class Point
{
        double x,y;

        public:
        Point();
        Point(size_t i);
        Point(double d);
        Point(double x, double y);
        friend Point operator+ (const Point & left,const Point & other);
        friend Point operator- (const Point & left,const Point & other);
	friend Point operator* (const Point & left,const Point & other);
	//friend Point operator+=(const Point & left,const Point & other);
        friend std::ostream& operator<< (std::ostream& o, const Point & p);
};

#endif

Point::Point(){x=0,y=0;}

Point::Point(size_t i){x=i,y=i;}

Point::Point(double d){x=d,y=d;}

Point::Point(double x, double y){this->x=x,this->y=y;}

Point operator+ (const Point & left, const Point & other){
	Point temp(left);
	temp.x += other.x;
	temp.y += other.y;
	return temp;
}
Point operator- (const Point & left, const Point & other){
	Point temp(left);
	temp.x -= other.x;
	temp.y -= other.y;
	return temp;
}
Point operator* (const Point & left, const Point & other){
	Point temp(left);
	temp.x *= other.x;
	temp.y *= other.y;
	return temp;
}
/*
Point operator+= (const Point & left, const Point & other){
	Point temp;
	//this->x += other.x;
	//this->y += other.y;
	return temp+other;
}
*/
std::ostream & operator << (std::ostream & o, const Point & p){
	o << '(' << p.x << ',' << p.y << ')';
	return o;
}
/*int main()
	{
		Point p0;
		std::cout << p0;
		Point p1 = {1,0};
		std::cout << p1;
		Point p2 = {4,5};
		std::cout << p2;
		std::cout << (p2 - p1);
		std::cout << (p2 + p1);
		return 0;
	}
*/
