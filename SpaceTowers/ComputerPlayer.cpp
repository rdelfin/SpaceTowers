//
//  ComputerPlayer.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 7/13/14.
//
//

#include "stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer()
{
	spawnFlag = false;
}

ComputerPlayer::ComputerPlayer(string towerFile, int xOffset, int yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp)
    : Player(towerFile, xOffset, yOffset, mapSize, initialCredits, initialCreditsPerSecond, yCharacterOffset, goingRight, info, towerHp)
{
	spawnFlag = false;
}

void ComputerPlayer::addCharacters(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    //TODO: ADD A REAL AI. NOT THIS CRAZY SPAWNING PIECE OF SHIT!
	if(credits >= characterList.getCharacterInfo(0)->getCost() + 2*characterList.getCharacterInfo(1)->getCost())
	{
		spawnCharacter(characterList.getCharacterInfo(0)->createCharacter(&credits, goingRight));
		spawnCharacter(characterList.getCharacterInfo(1)->createCharacter(&credits, goingRight));
		spawnCharacter(characterList.getCharacterInfo(1)->createCharacter(&credits, goingRight));

	}
	/*
	if(spawnFlag && characterList.getCharacterInfo(0)->getCost() <= credits) {
		spawnCharacter(characterList.getCharacterInfo(0)->createCharacter(&credits, goingRight));
		spawnFlag = !spawnFlag;
	}
	else if(!spawnFlag && characterList.getCharacterInfo(1)->getCost() <= credits) {
		spawnCharacter(characterList.getCharacterInfo(1)->createCharacter(&credits, goingRight));
		spawnFlag = !spawnFlag;
	}*/
}