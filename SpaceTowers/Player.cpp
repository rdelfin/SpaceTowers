//
//  Player.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/23/14.
//
//

#include "stdafx.h"

#include "Player.h"


Player::Player()
{
    
}

Player::Player(string towerFile, double xOffset, double yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp)
{
	this->tower = Tower(towerFile, xOffset, yOffset, yCharacterOffset, mapSize, goingRight, towerHp);
    this->credits = initialCredits;
    this->creditsPerSecond = initialCreditsPerSecond;
    this->goingRight = goingRight;
    this->timer = 0;
    this->characterList = CharacterList(info);
}


void Player::Update(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, Player* enemy)
{
    for(unsigned int i = 0; i < character.size(); i++)
		character[i]->Update(gameTime, enemy->character, &enemy->tower);
    
    timer += gameTime->getMillisecondsPerFrame();
    
    if(timer >= 1000)
    {
        credits += creditsPerSecond;
        timer = 0;
    }
    
    addCharacters(gameTime, keyState, prevKeyState, mouseState, prevMouseState);
    
    vector<Character*> newCharacter = characterList.getCreatedCharacters();
    
    for(unsigned int i = 0; i < newCharacter.size(); i++)
        spawnCharacter(newCharacter[i]);
    
    clearCharacterList();
}

void Player::Draw(Vector2 camPos)
{
    for(unsigned int i = 0; i < character.size(); i++)
        character[i]->Draw(camPos);
    
	tower.Draw(camPos);
}

void Player::spawnCharacter(Character* c)
{
	c->setLowerRightPosition(tower.getSpawnPoint());
    character.push_back(c);
}

void Player::clearCharacterList()
{
    vector<long> toDelete;
    
    for(long i = character.size() - 1; i >= 0; i--)
        if(character[i]->isDead())
           toDelete.push_back(i);
    
    for(unsigned int i = 0; i < toDelete.size(); i++)
    {
        Character* temp = character[toDelete[i]];
        character[toDelete[i]] = character[character.size() - 1];
        character[character.size() - 1] = temp;
        //delete character[character.size() - 1];
        character.pop_back();
    }
}

Player::~Player()
{

}

