/*!
 *  @header Projectile
 *  File for the Projectile and Projectile Generator classes
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "GameObject.h"

class Character;


/*!
 *  Class that represents a character bullet or projectile. It has the entire game logic to allow for
 *  it to detect when it collides with a character and to alert that it should be destroyed in the
 *  list of bullets. It extends GameObject, and, as such, is capable of having velocity and acceleration
 *  programmed into it.
 *
 *  @abstract Class used to represent a bullet or projectile for a character
 *  @updated 2014-07-19
 */
class Projectile : public GameObject {
public:
    Projectile();
    Projectile(Vector2 position, bool goingRight, double speed, double damage, string path, Vector2 frameCount = Vector2(1, 1), double millPerFrame = 200);
    
    /*!
     *  Update method for the bullet. Is in charge of moving the bullet and detecting collisions with
     *  any of the enemy, or target characters.
     *
     *  @param gameTime Instance of GameTime* that saves all the information about the time since the
     *  last frame as well as the time since the begining of the game.
     *  @param enemies  List of all characters that can be hit by this bullet. In other words, the
     *  enemies, or targets of the bullet
     */
    void Update(GameTime* gameTime, vector<Character*> enemies);
    
    /*!
     *  Draw method for the bullet. Simply draws the bullet on the screen
     *
     *  @param camPos Position of the camera on the level. Basically this is subtracted from the
     *  position.
     */
    void Draw(Vector2 camPos);
    
    /*!
     *  Tells you if the projectile has hit a player and should be destroyed or removed from the list
     *  of bullets.
     *
     *  @return True if it should be destroyed/removed, false otherwise
     */
    bool isDead();
    
private:
    double speed, damage;
    bool dead, goingRight;
};


class ProjectileGenerator {
public:
    ProjectileGenerator();
    ProjectileGenerator(double speed, double damage, bool goingRight, string imgPath, Vector2 imgFrameCount = Vector2(1, 1), double imgMillPerFrame = 200);
    
    /*!
     *  Creates a projectile and returns a pointer to it (to allow polymorphism if this class is
     *  extended). This would be added to the list of projectiles in a Character
     *
     *  @param position   Position where the bullet will be spawned/created. This is center defined
     *
     *  @return The projectile created from this process. This is a pointer to allow polymorphism
     */
    virtual Projectile* generateProjectile(Vector2 position);
    
private:
    Projectile projectile;
    
};
