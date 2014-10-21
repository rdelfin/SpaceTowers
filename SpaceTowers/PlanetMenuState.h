/*!
 * @header Planet Menu State
 * State for the planet button menu
 * @author Ricardo Delfin Garcia
 * @language C++
 * @version 1.0
 */

#pragma once

#include "stdafx.h"
#include "GameState.h"
#include "PlanetButton.h"

/*!
 * This is the game state for the menu where you can find all the planets rotating. When you
 * click one of those planets, it sends you out to a specific menu, accoring to what the button does.
 * @abstract The game state for the rotating planets menu
 * @updated 2014-07-05
 */
class PlanetMenuState : public GameState {
    
public:
    PlanetMenuState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, vector<PlanetButton> planets);
    
    /*!
     *  General update method for the game state. This is overwriting the virtual funcion of the same
     *  name in GameState. It basically updates the planets and calculates the anyHovered parameter for
     *  the PlanetButton Update method.
     *
     *  @param gameTime Instance of GameTime* that holds the information for the time since the game 
     *  began and the time since the last update loop
     */
    void Update(GameTime* gameTime);
    
	/*!
	 *  General drawing method for the game state. This overwrites the virtual funcion of the same name
     *  in GameState. It basically draws the background and, on top of that, calls the Draw method for
     *  each of the items in the planets vector.
	 */
	void Draw();
    
    /*!
     *  Gets the endState variable, which indicates how the state ended (which planet button was pressed)
     *  Values:
     *  1- Play
     *  2- Instructions
     *  3- Back
     *  4- Quit
     *
     *  @return The endState
     */
    int getEndState();
    
private:
    ALLEGRO_BITMAP* background;
    vector<PlanetButton> planets;
    int endState;
    
};