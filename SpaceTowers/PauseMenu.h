#pragma once
#include "GameObject.h"
#include "Button.h"

class PauseMenu :
	public GameObject
{
public:
	PauseMenu();
	PauseMenu(Vector2 screenSize);
	~PauseMenu();

	
	void Update(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
	virtual void Draw(Vector2 camPos);

	bool finished();
	void reset();

private:
	Button button;
	bool done;
};

