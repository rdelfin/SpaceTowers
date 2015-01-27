#include "stdafx.h"
#include "GameState.h"

GameState::GameState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
	this->screenSize = screenSize;
	running = true;
	this->keyState = keyState;
	this->prevKeyState = prevKeyState;
	this->mouseState = mouseState;
	this->prevMouseState = prevMouseState;
}

Vector2 GameState::getScreenSize() { return screenSize; }

void GameState::stop() { running = false; }
bool GameState::isRunning() { return running; }

GameState::~GameState(void)
{
}
