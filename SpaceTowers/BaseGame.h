#include "Vector2.h"
#include "GameTime.h"

#pragma once

enum ScreenType
{
	FULLSCREEN,
	FULLSCREEN_WINDOWED,
	WINDOW
};

class BaseGame
{
public:

	//Constructors
    
	BaseGame(Vector2 windowSize, ScreenType screenType, string windowTitle, double fps);
    BaseGame();

	//Getters and Setters
	Vector2 getWindowSize();
	void stop();

	//Update and Draw
	virtual void Update(GameTime*) = 0;
	virtual void Draw(GameTime*) = 0;

	//Run
	void run();

	virtual ~BaseGame();


protected:
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_KEYBOARD_STATE prevKeyState;
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_MOUSE_STATE prevMouseState;
	
	ALLEGRO_DISPLAY* display;

private:
	void initScreen(ScreenType, string);
	void initModules();

	Vector2 windowSize;
	GameTime* gameTime;
	bool running;

	const double fps;

	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE* eventQueue;
};

