/*!
 *  @header Level
 *  File with the class for the general Level class, which loads and runs the levels
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "Player.h"

/*!
 *  This is the general class for a level. Through this class you load a level and run all
 *  the players and continuous game logic for such a level. 
 *
 *  @abstract General class for any game level.
 *
 *  @updated 2014-07-05
 */
class Level {
public:
    
    Level(Vector2 screenSize);
    
    /*!
     *  Method to be called for the update cycle of the level. Form here, the camera movement if managed
     *  and the two players are updated, which in turn update their towers, their spawn logic and their
     *  characters.
     *
     *  @param gameTime       Instance of GameTime* that contains the information for the running time
     *  for the game as well as the time since the last cycle
     *  @param keyState       Instance of ALLEGRO_KEYBOARD_STATE* with the information for the current
     *  state of all the keyboard keys.
     *  @param prevKeyState   Instance of ALLEGRO_KEYBOARD_STATE* with the information for the state of
     *  all the keyboard keys <b>in the previous update cycle</b>.
     *  @param mouseState     Instance of ALLEGRO_MOUSE_STATE* with the information for the current state
     *  of the mouse, both buttons and position.
     *  @param prevMouseState Instance of ALLEGRO_MOUSE_STATE* with the information for the state of the
     *  mouse, both buttons and position <b>in the previous frame</b>.
     */
    void Update(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
    
    /*!
     *  Method to be called for the draw cycle of the level. From here, the map is drawn, and the draw
     *  method for the two players is also called.
     */
    void Draw();
    
private:
    
    Player *human, *computer;
    ALLEGRO_BITMAP* background;
    Vector2 camPos, screenSize;

	/*--------------------------------------------------------------------------------------------------------------
	  ------------------------------------------ CONSTANTS ---------------------------------------------------------
	  --------------------------------------------------------------------------------------------------------------*/
	static const double CAM_SPEED;
    
};
