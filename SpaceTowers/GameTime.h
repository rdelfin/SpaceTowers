#pragma once
class GameTime
{
public:
	GameTime();
	~GameTime();

	void Update();
	long double getMillisecondsPerFrame();
	long double getElapsedGameTime();

	static long double milliseconds_now();

	void reset();

private:
	long double start;
	long double lastFrame;
	long double currFrame;

};

