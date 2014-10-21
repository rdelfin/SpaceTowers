#pragma once
#include "Vector2.h"
class GameRectangle
{
public:
	GameRectangle();
	GameRectangle(double x, double y, double width, double height);

	GameRectangle operator+(GameRectangle);
	GameRectangle operator+(Vector2);
	GameRectangle operator-(GameRectangle);
	GameRectangle operator-(Vector2);

	bool contains(Vector2);
	bool contains(GameRectangle);
	bool intersects(GameRectangle);

	~GameRectangle();
	
	double x, y, width, height;

	double bottom();
	double top();
	double right();
	double left();


};

