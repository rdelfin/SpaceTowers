/*!
 * @header Character List
 * @author Ricardo Delfin Garcia
 * @language C++
 * @version 1.0
 */


#pragma once

#include "stdafx.h"
#include "CharacterInfo.h"

/*!
 *  This class provides the List of characters that can be used by a Player. This also draws the buttons
 *  for adding the characters, if necesary.
 *  @abstract List of characters for the Player class.
 *  @updated 2014-07-13
 */
class CharacterList {
public:
    CharacterList();
    CharacterList(vector<CharacterInfo*> info);
    
    /*!
     *  Update method for the character list. This is only useful if you are using character buttons
     *  to create the characters. In other words, if this is for the human player.
     *
     *  @param gameTime       Instance of GameTime* that contains the information for the running time 
     *  for the game as well as the time since the last cycle
     *  @param mouseState     Instance of ALLEGRO_MOUSE_STATE* with information about the current mouse
     *  position as well as the state of the mouse buttons.
     *  @param prevMouseState Instance of ALLEGRO_MOUSE_STATE* with information about the mouse
     *  position as well as the state of the mouse buttons <b>in the previous update cycle</b>.
     *  @param coins          The coins that are to be spent when a character is created.
     *  @param goingRight     True if the characters that are going to be created will move to the right.
     *  False otherwise
     */
    void Update(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, COINS* coins, bool goingRight);
    
    /*!
     *  The draw cycle for the character list. This will only display the buttons. Do not use if this is
     *  not the human player.
     */
    void Draw();
    
    /*!
     *  Get the CharacterInfo class for a specifi index inside this list.
     *
     *  @param index Index of the CharacterInfo class inside this list
     *
     *  @return A pointer to the CharacterInfo class.
     */
    CharacterInfo* getCharacterInfo(int index);
    
    
    /*!
     *  Get the size of the this CharacterInfo list
     *
     *  @return The size of said list
     */
    size_t getCharacterInfoCount();
    
    
    /*!
     *  Get all the characters that have been created since this method was last called. This will create
     *  a copy of the list of created characters, return said list and clear the list that is stored
     *  inside this class.
     *
     *  @return A list of characters to add to the current character list.
     */
    vector<Character*> getCreatedCharacters();
    
    
    /*!
     *  Method to force the creation of a character of a specific type. This will add it to the list of
     *  created characters for use in the getCreatedCharacters method.
     *
     *  @param index      Index of the CharacterInfo from which the character will be created.
     *  @param coins      Coins which will be spent to create this character
     *  @param goingRight True if the character to be created is going to go towards the right. False
     *  otherwise.
     */
    void createCharacter(int index, COINS* coins, bool goingRight);
    
private:
    vector<CharacterInfo*> characters;
    vector<Character*> createdCharacters;
};