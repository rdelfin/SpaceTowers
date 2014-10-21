#pragma once

class Complex;

class Vector2
{
public:
	Vector2(double x, double y);
	Vector2();

	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);

	Vector2 operator+(double);
	Vector2 operator-(double);

	Vector2 operator*(double);
	Vector2 operator/(double);

	double length();
	double angle();

	Vector2 normalize();

	~Vector2(void);
	
	double x, y;
};

