/*!
 *  @header Player
 *  File with the header for the player class
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */
#pragma once

#include "stdafx.h"
#include "Vector2.h"
#include "GameTime.h"
#include "Character.h"
#include "CharacterList.h"
#include "Tower.h"

/*!
 *  Class that represents one of the players inside a level. This can be either a human
 *  player or an AI (this depends on how the @link addCharacters @/link method is overwritten). The draw
 *  and update methods must be called so the towers, characters and any other information can be drawn
 *  and properly updated in the game cycle.
 *  @abstract This represents a player, either AI or human, in a level state, with its respective tower,
 *  charaters and buttons (if applicable)
 *  @updated 2014-07-05
 */
class Player {
public:
    Player();
    Player(string towerFile, double xOffset, double yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp);
    
    /*!
     *  Update cycle for the player. From here, the characters are updated, and any buttons that might
     *  be pressed are updated. Also, the addCharacters method is called from here.
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
     *  @param enemy          Enemy player against which the level is being played
     */
    virtual void Update(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, Player* enemy);
    
    /*!
     *  Draw method for the player. From here, all the characters are drawn, as well as the tower.
     *
     *  @param camPos Position of the camera. Comes out as a displacement of all objects by negative 
     *  camPos
     */
    virtual void Draw(Vector2 camPos);
    
    /*!
     *  Pure virtual method for adding the characters. This varies deppending on the type of player.
     *  For example, a human player will do so through a graphic interface while an AI player will chose
     *  the player based on an artificial inteligence algorithm. As such, the character vector is
     *  expanded from here, through the spawnCharacter method and the CharacterInfo's methods for 
     *  spawning.
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
    virtual void addCharacters(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState) = 0;
    
    /*!
     *  This method adds a character to the character vector and moves it to the apropriate position 
     *  (wherever the player's spawn point may be)
     *
     *  @param c Character to add to the vector
     */
    void spawnCharacter(Character* c);

	bool alive();
    
    ~Player();
    
    
protected:
    CharacterList characterList;
    
    COINS credits;
    COINS creditsPerSecond;

    vector<Character*> character;
    
	Tower tower;
    
    bool goingRight;
    
    double timer;
    
    void clearCharacterList();
};