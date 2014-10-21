#include "stdafx.h"
#include "GameRectangle.h"

GameRectangle::GameRectangle()
{
	GameRectangle(0, 0, 0, 0);
}

GameRectangle::GameRectangle(double x, double y, double width, double height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

GameRectangle GameRectangle::operator+(GameRectangle r)
{ return GameRectangle(x + r.x, y + r.y, width + r.width, height + r.height); }
GameRectangle GameRectangle::operator+(Vector2 v)
{ return GameRectangle(x + v.x, y + v.y, width, height); }
GameRectangle GameRectangle::operator-(GameRectangle r)
{ return *this + GameRectangle(-r.x, -r.y, -r.width, -r.height); }
GameRectangle GameRectangle::operator-(Vector2 v)
{ return *this + Vector2(-v.x, -v.y); }

bool GameRectangle::contains(Vector2 v)
{
	bool horizontalInside = v.x > x && v.x < x + width;
	bool verticalInside = v.y > y && v.y < y + height;
	return horizontalInside && verticalInside;
}

bool GameRectangle::contains(GameRectangle r)
{
	bool horizontalContains = r.x >= x && r.x + r.width <= x + width;
	bool verticalContains = r.y >= y && r.y + r.height <= y + height;

	return horizontalContains && verticalContains;
}

bool GameRectangle::intersects(GameRectangle r)
{
	bool horizontalInside = x + width > r.x && x < r.x + r.width;
	bool verticalInside = y + height > r.y && y < r.y + r.height;

	return horizontalInside && verticalInside;
}

double GameRectangle::bottom() { return y + height; }
double GameRectangle::top() { return y; }
double GameRectangle::left() { return x; }
double GameRectangle::right() { return x + width; }

GameRectangle::~GameRectangle(void)
{

}
