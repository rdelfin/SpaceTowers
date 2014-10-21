#pragma once

#include "Vector2.h"
#include "GameObject.h"

class GameState
{
public:
	GameState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);

	Vector2 getScreenSize();
	void stop();
	bool isRunning();

	virtual void Update(GameTime*) = 0;
	virtual void Draw() = 0;

	virtual ~GameState(void);

protected:
	ALLEGRO_KEYBOARD_STATE *keyState, *prevKeyState;
    ALLEGRO_MOUSE_STATE *mouseState, *prevMouseState;

private:
	Vector2 screenSize;
	bool running;
};

