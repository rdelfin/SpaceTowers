//
//  Projectile.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 7/17/14.
//
//

#include "stdafx.h"
#include "Projectile.h"
#include "Character.h"

/*===============================================================================================
  ============================================ Projectile =======================================
  ===============================================================================================*/

Projectile::Projectile()
{
    
}

Projectile::Projectile(Vector2 position, bool goingRight, double speed, double damage, string path, Vector2 frameCount, double millPerFrame)
    : GameObject(path, frameCount, millPerFrame, position)
{
    this->dead = false;
    this->speed = speed;
    this->damage = damage;
    this->velocity = Vector2((goingRight ? speed : -speed), 0);
    this->goingRight = goingRight;
    
    sprite->flip(!goingRight);
}


void Projectile::Update(GameTime* gameTime, vector<Character*> enemies)
{
    GameObject::Update(gameTime);
    
    for(unsigned int i = 0; i < enemies.size(); i++)
    {
        GameRectangle enemyRect = GameRectangle(enemies[i]->position.x, enemies[i]->position.y, enemies[i]->getFrameSize().x, enemies[i]->getFrameSize().y);
        
        if(enemies[i]->getRectangle().intersects(getRectangle()))
        {
            dead = true;
            enemies[i]->reduceHp(damage);
		}
    }
}

void Projectile::Draw(Vector2 camPos)
{
    GameObject::Draw(camPos);
}


bool Projectile::isDead() { return dead; }



/*==============================================================================================
  ====================================== Projectile Generator ==================================
  ==============================================================================================*/


ProjectileGenerator::ProjectileGenerator()
{
    
}


ProjectileGenerator::ProjectileGenerator(double speed, double damage, bool goingRight, string imgPath, Vector2 imgFrameCount, double imgMillPerFrame)
{
    this->projectile = Projectile(Vector2(), goingRight, speed, damage, imgPath, imgFrameCount, imgMillPerFrame);
}

Projectile* ProjectileGenerator::generateProjectile(Vector2 position)
{
    Projectile* result = new Projectile(projectile);
    result->position = position - result->getFrameCount() / 2;
    return result;
}


