//
//  SuperSpaceMarine.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 8/1/14.
//
//

#include "stdafx.h"
#include "SuperSpaceMarine.h"
#include "Projectile.h"

//------------------------------------------------------------------------------------------------
//------------------------------------------- Character ------------------------------------------
//------------------------------------------------------------------------------------------------

SuperSpaceMarine::SuperSpaceMarine()
{
    
}

SuperSpaceMarine::SuperSpaceMarine(Vector2 initialPosition, bool goingRight)
: Character("assets/img/characters/superSpaceMarineWalking.png", Vector2(8, 1), 100, "assets/img/characters/superSpaceMarineAttack.png", Vector2(1, 1), 200, initialPosition, 0.12, 100, 200, 150, goingRight, new ProjectileGenerator(0.3, 10, goingRight, "assets/img/characters/bullet2.png", Vector2(2, 1), 50))
{
    
}


void SuperSpaceMarine::Update(GameTime* gameTime, vector<Character*> enemies)
{
    Character::Update(gameTime, enemies);
}


void SuperSpaceMarine::Draw(Vector2 camPos)
{
    Character::Draw(camPos);
}


SuperSpaceMarine::~SuperSpaceMarine()
{
    this->Character::~Character();
}



/*------------------------------------------------------------------------------------------------
  --------------------------------------- CharacterInfo ------------------------------------------
  ------------------------------------------------------------------------------------------------*/

SuperSpaceMarineInfo::SuperSpaceMarineInfo(Vector2 position)
: CharacterInfo(2, "assets/img/Buttons/characters/superSpaceMarineDefault.png", "assets/img/Buttons/characters/superSpaceMarinePressed.png", position)
{
    
}


Character* SuperSpaceMarineInfo::createCharacter(COINS* coins, bool goingRight)
{
    if(CharacterInfo::buyCharacter(coins))
    {
        return new SuperSpaceMarine(Vector2(), goingRight);
    }
    
    return NULL;
}