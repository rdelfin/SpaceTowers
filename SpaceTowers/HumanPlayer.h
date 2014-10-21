/*!
 *  @header Human Player
 *  File with the code for the human version of the player class
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */


#pragma once

#include "Player.h"

/*!
 *  Class that represents the human version of the @link Player @/link class. It has buttons
 *  for buying the characters, which exist through the @link CharacterList @/link class. While, 
 *  potentially, you could have more than one instance of this class in the same level, this is not the
 *  purpouse of the class and it would not work as such.
 *  @abstract This represents the human player, which, unlike an AI player, adds characters through
 *  buttons found at the bottom of the screen.
 *  @updated 2014-07-05
 */
class HumanPlayer : public Player {
public:
    
    HumanPlayer();
    HumanPlayer(string towerFile, int xOffset, int yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp);
    
    /*!
     *  Method from which the characters are added for the human player. This only updates the buttons
     *  and adds the characters using methods from CharacterInfo and Player. They are not drawn from here
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
    virtual void addCharacters(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
    
    /*!
     *  Has the draw cycle for the human player. It draws the Player part of this cycle, as well as the
     *  character buttons and the coin text.
     *
     *  @param camPos The position of the camera
     */
    virtual void Draw(Vector2 camPos);
    
private:
    ALLEGRO_FONT* font;
};
