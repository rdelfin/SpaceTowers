//
//  SpaceMarine.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 7/2/14.
//
//

#include "stdafx.h"
#include "SpaceMarine.h"
#include "Projectile.h"

//------------------------------------------------------------------------------------------------
//------------------------------------------- Character ------------------------------------------
//------------------------------------------------------------------------------------------------

SpaceMarine::SpaceMarine()
{
    
}

SpaceMarine::SpaceMarine(Vector2 initialPosition, bool goingRight)
    : Character("assets/img/characters/WalkingRight.png", Vector2(6, 1), 200, "assets/img/characters/FiringRight.png", Vector2(4, 1), 200, initialPosition, 0.1, 50, 300, 100, goingRight, new ProjectileGenerator(0.3, 10, goingRight, "assets/img/characters/bullet.png"))
{
    
}


void SpaceMarine::Update(GameTime* gameTime, vector<Character*> enemies)
{
    Character::Update(gameTime, enemies);
}


void SpaceMarine::Draw(Vector2 camPos)
{
    Character::Draw(camPos);
}


SpaceMarine::~SpaceMarine()
{
    this->Character::~Character();
}




/*------------------------------------------------------------------------------------------------
  --------------------------------------- CharacterInfo ------------------------------------------
  ------------------------------------------------------------------------------------------------*/

SpaceMarineInfo::SpaceMarineInfo(Vector2 position)
    : CharacterInfo(1, "assets/img/Buttons/characters/marineDefault.png", "assets/img/Buttons/characters/marinePressed.png", position)
{
    
}


Character* SpaceMarineInfo::createCharacter(COINS* coins, bool goingRight)
{
    if(CharacterInfo::buyCharacter(coins))
    {
        return new SpaceMarine(Vector2(), goingRight);
    }
    
    return NULL;
}
