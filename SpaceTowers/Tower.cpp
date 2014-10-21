//
//  Tower.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 8/13/14.
//
//

#include "stdafx.h"
#include "Tower.h"

Tower::Tower()
{

}

Tower::Tower(string file, double xOffset, double yOffset, double yCharacterOffset, Vector2 mapSize, bool goingRight, double hp)
    : GameObject(file, Vector2(1, 1), 200, position)
{
	if(goingRight)
    {
		position = Vector2(xOffset, mapSize.y - yOffset - getFrameSize().y);
		relSpawnPoint = Vector2(xOffset + getFrameSize().x, mapSize.y - yCharacterOffset);
    }
    else
    {
		position = Vector2(mapSize.x - xOffset - getFrameSize().x, mapSize.y - yOffset - getFrameSize().y);
		relSpawnPoint = Vector2(mapSize.x - xOffset - getFrameSize().x, mapSize.y - yCharacterOffset);
    }

    this->hp = hp;
}

void Tower::hit(int hpHit) { this->hp -= hpHit; }

bool Tower::isDestroyed() { return hp <= 0; }

Vector2 Tower::getSpawnPoint() { return relSpawnPoint; }

void Tower::Update(GameTime* gameTime)
{
	GameObject::Update(gameTime);
}

void Tower::Draw(Vector2 camPos)
{
	GameObject::Draw(camPos);
}
