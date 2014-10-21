/*!
 *  @header Space Marine
 *  File with the SpaceMarine and its joint Character Information class.
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "Character.h"
#include "CharacterInfo.h"

/*!
 *  Default soldier type for the game. It has a standard speed, as well as a standard
 *  attack.
 *  
 *  Stats:
 *  
 *  1. Speed: 0.1 pixels/ms
 *  2. Range: 50 pixels
 *  3. Health: 100 HP
 *
 *  @abstract Standard soldier character for any player. Has standard speed, range and attack
 *  @updated 2014-07-06
 */
class SpaceMarine : public Character {
public:
    
    SpaceMarine();
    SpaceMarine(Vector2 initialPosition, bool goingRight);
    
    
    /*!
     *  Update cycle for the Space Marine. Simply calls the update of Character
     *
     *  @param gameTime Instance of GameTime* that contains the information for the time since the game
     *  began and the time since the last update cycle.
     *  @param enemies  The vector containing all the characters this character can attack (in other
     *  words, enemy characters).
     */
    virtual void Update(GameTime* gameTime, vector<Character*> enemies);
    
	/*!
	 *  Draw cycle for the Space Marine. It simply calls the Draw from its parent class, character
	 *
	 *  @param camPos Position of the camera. More detailed explanation can be found in the Character
     *  class.
	 */
	virtual void Draw(Vector2 camPos);
    
    virtual ~SpaceMarine();
};


/*!
 *  Information class for the @link SpaceMarine @/link class. Information:
 *  
 *  - Cost: 2
 *
 *  @abstract Information class for the @link SpaceMarine @/link class.
 *  @updated 2014-07-06
 */
class SpaceMarineInfo : public CharacterInfo {
public:
    
    SpaceMarineInfo(Vector2 position);
    
    /*!
     *  Method that creates the character. In this case, it will return a character of type SpaceMarine.
     *
     *  @param coins Pointer to the coins used by the player
     *  @param goingRight True if the character should be moving towards the right
     *
     *  @return An instance of SpaceMarine, or NULL if there is not enough money
     */
    Character* createCharacter(COINS* coins, bool goingRight);
};

