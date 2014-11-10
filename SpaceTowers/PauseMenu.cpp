#include "stdafx.h"
#include "PauseMenu.h"


PauseMenu::PauseMenu(void)
{

}
PauseMenu::PauseMenu(Vector2 screenSize)
	: GameObject("assets/img/level/menu/pauseMenu.png", Vector2(1, 1), 200, Vector2())
{
	position = Vector2(screenSize.x / 2 - getFrameSize().x / 2, screenSize.y / 2 - getFrameSize().y / 2);
		
	//                      main image                                                      click image                                              
	button = Button("assets/img/level/menu/StartButton.png", Vector2(1, 1), 200, "assets/img/level/menu/StartButtonPressed.png",
		//        hover image
		Vector2(1, 1), 200, "", Vector2(1, 1), 200, Vector2(1, 1), false);

	button.position = Vector2((getFrameSize().x - button.getFrameSize().x) / 2 + position.x, (getFrameSize().y - button.getFrameSize().y) / 2 + position.y);

	done = false;
}


void PauseMenu::Update(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
	GameObject::Update(gameTime);
	button.Update(gameTime, mouseState, prevMouseState);
	if(button.wasJustReleased())
		done = true;
}

void PauseMenu::Draw(Vector2 camPos)
{
	GameObject::Draw(Vector2());
	button.Draw(Vector2());
}

bool PauseMenu::finished(){ return done; }

void PauseMenu::reset() { done = false; }

PauseMenu::~PauseMenu(void)
{
}
