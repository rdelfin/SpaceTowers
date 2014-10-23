/*!
 *  @header Game Level State
 *  File with the basic Game Level State (creates a level state)
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "stdafx.h"
#include "GameState.h"
#include "Player.h"
#include "Level.h"

/*!
 *  Class that represents a game level's state. It creates the state based on the parameters passed
 *  through the constructor. It creates a Level object based on said parameters and simply updates
 *  and draws it.
 *
 *  @abstract Class that represents any and all game level's state.
 *  @updated 2014-08-17
 */
class GameLevelState : public GameState {
public:
    GameLevelState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
    
	virtual void Update(GameTime*);
	virtual void Draw();
private:
    Level level;
	bool paused;
};
