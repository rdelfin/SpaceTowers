/*!
 *  @header Character Information
 *  This is the file for the Character Information class, which saves the information for a character
 *  type.
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */


#pragma once

#include "Character.h"
#include "Button.h"

/*!
 *  This class contains a representation of the information for a character type. It is
 *  created so that there is only one instance of this class per character type used in a player. 
 *  It has update and draw methods for the button, if the player is a human player. It also uses the
 *  abstract @link createCharacter @/link method for returning a new character with the apropriate
 *  properties and behaviours. AS SUCH, THIS CLASS IS MEANT TO BE INHERITED TOGETHER WITH THE CHARACTER
 *  CLASS AND WILL BE USELESS OTHERWISE.
 *  @abstract With this you can represent and save the information for a character TYPE. It also contains
 *  a method to create a character of the type it is representing. IT IS AN ABSTRACT CLASS
 *  @updated 2014-07-06
 */
class CharacterInfo {
public:
    CharacterInfo();
    CharacterInfo(COINS cost, string defaultFile, string selectedFile, Vector2 position);
    
    /*!
     *  Method that creates a character of the type that is being represented by the CharacterInfo. It
     *  also buys the character. In other words, it lowers the money in accordance to the cost. This
     *  is a pure virtual funcion as it must be overwritten by any child class returning the correct
     *  type of character. As such, it must use the buyCharacter method.
     *
     *  @param coins Coins which are being spent
     *  @param goingRight True if the character should move towards the right
     *
     *  @return A new character pointer of the correct type, or NULL if there is not enough money.
     */
    virtual Character* createCharacter(COINS* coins, bool goingRight) = 0;
    
    
    /*!
     *  Update cycle for the button for buying the character as a human player.
     *
     *  @param gameTime       Instance of GameTime* which contains the information for the time since the
     *  begining of the game, as well as the time since the last cycle.
     *  @param mouseState     Instance of ALLEGRO_MOUSE_STATE* with information about the current mouse
     *  position as well as the state of the mouse buttons.
     *  @param prevMouseState Instance of ALLEGRO_MOUSE_STATE* with information about the mouse
     *  position as well as the state of the mouse buttons <b>in the previous update cycle</b>.
     */
    void updateButton(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
    
    /*!
     *  Draw cycle for the button used for bying the character as a human player.
     */
    void drawButton();
    
    
    /*!
     *  Method used to know whether the button was just clicked. Because of this, this will only return
     *  true for one frame (the duration of one update cycle)
     *
     *  @return True if the button was just clicked (here defined as the frame in which the button was
     *  released
     */
    bool clickedButton();
    
    /*!
     *  Method used to get the cost of the character to which this CharacterInfo class refers.
     *
     *  @return Cost of the character
     */
    COINS getCost();
    
protected:
    
    /*!
     *  Method which reduces the number of coins from the parameter by the cost of the character, only
     *  if there are enough coins available
     *
     *  @param coins Pointer to the variable storing the coins available to the player
     *
     *  @return True if the player has enough coins. False otherwise.
     */
    bool buyCharacter(COINS* coins);
    
private:
    COINS cost;
    Button button;
};