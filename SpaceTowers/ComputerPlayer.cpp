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
    
}

ComputerPlayer::ComputerPlayer(string towerFile, int xOffset, int yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp)
    : Player(towerFile, xOffset, yOffset, mapSize, initialCredits, initialCreditsPerSecond, yCharacterOffset, goingRight, info, towerHp)
{
    
}

void ComputerPlayer::addCharacters(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    //TODO: ADD A REAL AI. NOT THIS CRAZY SPAWNING PIECE OF SHIT!
    if(characterList.getCharacterInfo(0)->getCost() <= credits)
        spawnCharacter(characterList.getCharacterInfo(0)->createCharacter(&credits, goingRight));
}