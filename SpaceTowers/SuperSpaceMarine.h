/*!
 *  @header SuperSpaceMarine
 *  File with the Super Space Marine and its joint CharacterInfo class
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "Character.h"
#include "CharacterInfo.h"

/*!
 *  Advanced version of the Space Marine (better stats, also more expensive)
 *  
 *  Stats:
 *
 *  1. Speed: 0.12 pixels/ms
 *  2. Range: 75 pixels
 *  3. Health: 110 HP
 *
 *  @abstract Advanced version of the Space Marine, with slightly better stats and higher cost
 *  @updated 2014-08-01
 */
class SuperSpaceMarine : public Character {
public:
    SuperSpaceMarine();
    SuperSpaceMarine(Vector2 initialPosition, bool goingRight);
    
    /*!
     *  Update cycle for the Super Space Marine. Simply calls the update of Character
     *
     *  @param gameTime Instance of GameTime* that contains the information for the time since the game
     *  began and the time since the last update cycle.
     *  @param enemies  The vector containing all the characters this character can attack (in other
     *  words, enemy characters).
     */
    virtual void Update(GameTime* gameTime, vector<Character*> enemies);
    
	/*!
	 *  Draw cycle for the Super Space Marine. It simply calles the Draw from its parent class, character
	 *
	 *  @param camPos Position of the camera. More detailed explanation can be found in teh Character
     *  class.
	 */
	virtual void Draw(Vector2 camPos);
    
    virtual ~SuperSpaceMarine();
    
};

/*!
 *  Information class for the SuperSpaceMarine class. Information:
 *
 *  - Cost: 5
 *
 *  @abstract Information class for the SuperSpaceMarine class.
 *  @updated 2014-08-01
 */
class SuperSpaceMarineInfo : public CharacterInfo {
public:
    SuperSpaceMarineInfo(Vector2 position);
    
    /*!
     *  Method that creates the character. In this case, it will return a character of type 
     *  SuperSpaceMarine.
     *
     *  @param coins Pointer to the coins used by the player
     *  @param goingRight True if the character should be moving towards the right
     *
     *  @return An instance of SuperSpaceMarine, or NULL if there is not enough money
     */
    Character* createCharacter(COINS* coins, bool goingRight);
};
