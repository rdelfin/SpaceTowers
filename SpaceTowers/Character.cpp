//
//  Character.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/23/14.
//
//

#include "stdafx.h"

#include "Character.h"

#include "Projectile.h"

Character::Character()
{
    
}

Character::Character(string walkFile, Vector2 walkFrameCount, int walkMillPerFrame, string attackFile, Vector2 attackFrameCount, int attackMillPerFrame, Vector2 initialPosition, double speed, double range, double fireRate, int maxHp, bool goingRight, ProjectileGenerator* pGenerator)
    : GameObject(walkFile, walkFrameCount, walkMillPerFrame, initialPosition)
{
    this->projectile = vector<Projectile*>();
    this->speed = speed;
    this->range = range;
    this->attackAnim = new Sprite(attackFile.c_str(), attackFrameCount, attackMillPerFrame);
    this->goingRight = goingRight;
    this->attacking = false;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->fireRate = fireRate;
    this->fireCounter = 0;
    this->pGenerator = pGenerator;
    
    if(!goingRight)
    {
        sprite->flip();
        attackAnim->flip();
    }
}

void Character::Update(GameTime* gameTime, vector<Character*> enemies, Tower* enemyTower)
{
    GameObject::Update(gameTime);
    attackAnim->Update(gameTime);
    
    //Check for enemies
    bool tempAttacking = false;
    
    //Update to change to attack state
    for(unsigned int i = 0; i < enemies.size(); i++)
    {
		double thisFront = (goingRight ? position.x + getRectangle().width : position.x);
		double otherFront = (goingRight ? enemies[i]->position.x : enemies[i]->position.x + enemies[i]->getRectangle().width);
		double differenceX = (goingRight ? otherFront - thisFront : thisFront - otherFront);

        if(differenceX < range && differenceX >= 0)
        {
			if(!attacking) {
				//starts firing as soon as enemy is seen
				fireCounter = fireRate;
			}
			
			tempAttacking = true;
            break;
        }
    }

	//Update attack state for tower specifically
	double towerDiff = (goingRight ? enemyTower->getRectangle().x - position.x - getFrameSize().x : position.x - enemyTower->getRectangle().x - enemyTower->getRectangle().width);
	if(towerDiff < range && towerDiff > 0) {
		if(!attacking) {
			//starts firing as soon as enemy is seen
			fireCounter = fireRate;
		}
			
		tempAttacking = true;
	}
	
	attacking = tempAttacking;
    
    //Fire bullets
	fireBullets(gameTime, enemies, enemyTower);
    
    //Clears all dead bullets from list
    cleanBulletList();
    
    //Set velocity
    velocity.x = (attacking ? 0 : (goingRight ? speed : -speed));
}




void Character::Draw(Vector2 camPos)
{
    for(unsigned int i = 0; i < projectile.size(); i++)
    {
        projectile[i]->Draw(camPos);
    }
    
    if(attacking)
        attackAnim->Draw(position - camPos);
    else
        GameObject::Draw(camPos);

	//Health bar
	int barWidth = 30 * hp / maxHp;
	int width = getFrameSize().x;
	int startX = position.x + width / 2 - barWidth / 2 - camPos.x;
	int endX = position.x + width / 2 + barWidth / 2 - camPos.x;
	al_draw_filled_rectangle(startX, position.y - 5 - camPos.y, endX, position.y - camPos.y, al_map_rgb(0, 255, 0));
}

bool Character::isDead() { return hp <= 0; }

void Character::reduceHp(int ammount) { hp -= ammount; }

void Character::setLowerRightPosition(Vector2 pos)
{
    this->position = Vector2(pos.x - sprite->getFrameSize().x, pos.y - sprite->getFrameSize().y);
}

void Character::cleanBulletList()
{
    vector<long> toDelete;
    
    for(long i = projectile.size() - 1; i >= 0; i--)
        if(projectile[i]->isDead())
            toDelete.push_back(i);
    
    for(unsigned int i = 0; i < toDelete.size(); i++)
    {
        Projectile* temp = projectile[toDelete[i]];
        projectile[toDelete[i]] = projectile[projectile.size() - 1];
        projectile[projectile.size() - 1] = temp;
        delete projectile[projectile.size() - 1];
        projectile.pop_back();
    }
}

void Character::fireBullets(GameTime* gameTime, vector<Character*> enemies, Tower* enemyTower)
{
    for (unsigned int i = 0; i < projectile.size(); i++)
        projectile[i]->Update(gameTime, enemies, enemyTower);
    
    if(attacking)
    {
        fireCounter += gameTime->getMillisecondsPerFrame();
        
        if(fireCounter >= fireRate)
        {
            fireCounter = 0;
            
            Vector2 projPosition = position + getFrameSize() / 2;
            
            projectile.push_back(pGenerator->generateProjectile(projPosition));
        }
    }
}

Character::~Character()
{
    this->GameObject::~GameObject();
    
    //for(int i = 0; i < projectile.size(); i++)
        //delete projectile[i];
    //delete attackAnim;
}

