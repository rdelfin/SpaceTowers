/*!
 * @header Computer Player
 * File that contains the computer player class
 * @author Ricardo Delfin Garcia
 * @version 1.0
 */

#pragma once

#include "Player.h"

/*!
 *  Class that represents a computer, or AI player. It simply overrides the addCharacters method from
 *  player and implements the AI in there. TODO: Add dificulty levels for the AI
 *
 *  @abstract Class that represents a computer player
 *
 *  @updated 2014-08-15
 */
class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    ComputerPlayer(string towerFile, int xOffset, int yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp);
    
    /*!
     *  Method where all the characters are added. In the case of this class, which represents the
     *  computer player, this is also from where all the AI logic is run. 
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
    
    
private:
    
};