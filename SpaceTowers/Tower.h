/*!
 *  @header Tower
 *  File with the tower class (represents a level tower)
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "GameObject.h"

/*!
 *  Class that represents the towers of any of the players. It saves basic information (hp, spawn point,
 *  sprite, etc.). From here, one can determine whether a player has lost or not.
 *
 *  @abstract Class that represents a player's tower.
 *  @updated 2014-08-17
 */
class Tower : public GameObject {
public:
    
	Tower();

    Tower(string file, double xOffset, double yOffset, double yCharacterOffset, Vector2 mapSize, bool goingRight, double hp);
    
    /*!
     *  Damages the tower with a specified ammount of HP, passed as a parameter
     *
     *  @param hpHit HP to lower from the tower
     */
    void hit(int hpHit);
    
    
    /*!
     *  Method used to determine if the tower has been destroyed (in other words, whether its HP has gone
     *  down to zero). Basically determines whether a player has been defeated.
     *
     *  @return True if the tower has been destroyed, false otherwise
     */
    bool isDestroyed();
    
    /*!
     *  Gets the spawn point (this is the point where the character will be spawned, set from the lower
     *  right corner if the character is moving left and the lower right corner if its moving right)
     *
     *  @return The spawn point as a Vector2
     */
    Vector2 getSpawnPoint();

	/*!
	 *  Update method for the Tower. Simply calls the parent's version
	 *  
	 *  @param gameTime Object that stores all the information on timing, time since last frame, and time since the start of the program/game
	 */
	void Update(GameTime* gameTime);
	
	/*!
	 *  Draw method for the Tower. Simply calls the parent's version
	 *  
	 *  @param camPos Relative position of the camera (upper left corner coordinate) in the 2D plane. Moves position of all objects by -camPos.
	 */
	void Draw(Vector2 camPos);
    
private:
    int hp;
    Vector2 relSpawnPoint;
    
};
