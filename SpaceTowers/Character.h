/*!
 *  @header Character
 *  File with the code for the general Character class
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "GameObject.h"
#include "Tower.h"

class Projectile;
class ProjectileGenerator;


/*!
 *  This contains the logic for a simple Character which walks forwards and fires from a
 *  certain range. The specific properties, as well as special behaviours, for a type of character can be
 *  set from children classes. It also contains a method for checking whether the character has been
 *  killed. FOR A LATTER IMPLEMENTATION: This will also display a death animation, together with a method
 *  to indicate if the character is dead but still running said animation.
 *  @abstract This contains the entire logic and drawing for any generic character. Any specifics have to 
 *  be created in child clases.
 *  @updated 2014-07-05
 */
class Character : public GameObject {
public:
    Character();
    
    Character(string walkFile, Vector2 walkFrameCount, int walkMillPerFrame, string attackFile, Vector2 attackFrameCount, int attackMillPerFrame, Vector2 initialPosition, double speed, double range, double fireRate, int maxHp, bool goingRight, ProjectileGenerator* pGenerator);
    
    
    /*!
     *  Update cycle for the character. From here, the sprites are updated, as well as the position of
     *  the character overall. Here is where the range, speed and HP information is used and handled.
     *
     *  @param gameTime  Instance of GameTime* that contains the information for the running time for the
     *                     game as well as the time since the last cycle
     *  @param enemies   The list of all enemy characters. This is so the player knows who to fire at.
	 *  @param tower     Enemy tower. This is used as a secondary target if no enemies are present.
     */
    virtual void Update(GameTime* gameTime, vector<Character*> enemies/*, Tower* enemyTower*/);
	
    /*!
     *  Draw method for the character. This method decides which image is appropriate to be drawn
     *  according to a series of boolean flags that have been set previously, in the Update method.
     *
     *  @param camPos Position of the camera. In other words, it dispaces what is being drawn by 
     *  negative camPos
     */
    virtual void Draw(Vector2 camPos);
    
    /*!
     *  Changes the position of the character from the lower right position instead of the standard
     *  upper left. Facilitates spawning the character (and is only recommended for this use).
     *
     *  @param pos Position to which move the characer.
     */
    void setLowerRightPosition(Vector2 pos);
    
    /*!
     *  Reduces the HP by the specified ammount.
     *
     *  @param ammount Ammount of HP reduced
     */
    void reduceHp(int ammount);
    
    /*!
     *  Checks if the character is currently dead and so should be deleted from the list of active
     *  characters.
     *
     *  @return True if the character is dead.
     */
    bool isDead();
    
    virtual ~Character();
    
protected:
    
    double speed, range, fireRate, fireCounter;
    int hp, maxHp;
    
    bool goingRight, attacking;
    
    Sprite* attackAnim;
    
    vector<Projectile*> projectile;
    
    ProjectileGenerator* pGenerator;
    
    /*!
     *  Small routine to clean the list of bullets (delete all bullets that are declared as dead).
     */
    void cleanBulletList();
    
    /*!
     *  Small routine with all the fire logic (moving bullets, generating them, etc.)
     *
     *  @param gameTime Instance of GameTime* that contains all the information for time passed since
     *  both the last frame and the begining of the game.
     *  @param enemies  List of the characters that are contained in the enemy Player. In other words,
     *  all the characters that can be hit by a bullet created by this character
     */
    void fireBullets(GameTime* gameTime, vector<Character*> enemies);
};