#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2(double x, double y)
{
	this->x = x;
	this->y = y;
}


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2 Vector2::operator+(Vector2 v)
{ return Vector2(x + v.x, y + v.y); }

Vector2 Vector2::operator-(Vector2 v)
{ return (*this) + Vector2(-v.x, -v.y); }

Vector2 Vector2::operator+(double v)
{ return (*this) + Vector2(v, v); }

Vector2 Vector2::operator-(double v)
{ return (*this) + (-v); }

Vector2 Vector2::operator*(double d)
{ return Vector2(x * d, y * d); }
Vector2 Vector2::operator/(double d)
{ return (*this) * (1/d); }


double Vector2::length()
{
	return sqrt(x*x + y*y);
}

double Vector2::angle()
{
	return acos(x / length());
}

Vector2 Vector2::normalize()
{
	return Vector2(x / length(), y / length());
}

Vector2::~Vector2(void)
{
}
