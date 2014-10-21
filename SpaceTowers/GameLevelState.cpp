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

}

void GameLevelState::Update(GameTime* gameTime)
{
    level.Update(gameTime, keyState, prevKeyState, mouseState, prevMouseState);
}

void GameLevelState::Draw()
{
    level.Draw();
}