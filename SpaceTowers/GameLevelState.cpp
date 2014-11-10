//
//  GameLevelState.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 7/3/14.
//
//

#include "stdafx.h"
#include "GameLevelState.h"
#include "HumanPlayer.h"

GameLevelState::GameLevelState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
    : GameState(screenSize, keyState, prevKeyState, mouseState, prevMouseState), level(screenSize)
{
	paused = true;
	
	pauseMenu = PauseMenu(screenSize);
}

void GameLevelState::Update(GameTime* gameTime)
{
	if(!al_key_down(keyState, ALLEGRO_KEY_P) && al_key_down(prevKeyState, ALLEGRO_KEY_P))
		paused = !paused;

	if(paused) {
		pauseMenu.Update(gameTime, mouseState, prevMouseState);
		if(pauseMenu.finished())
			paused = !paused;
	}
	else
		level.Update(gameTime, keyState, prevKeyState, mouseState, prevMouseState);
}

void GameLevelState::Draw()
{
    level.Draw();

	if(paused)
	{
		pauseMenu.Draw(Vector2());
	}
}