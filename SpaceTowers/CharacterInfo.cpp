
//
//  CharacterInfo.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/30/14.
//
//

#include "stdafx.h"
#include "CharacterInfo.h"

CharacterInfo::CharacterInfo() { }

CharacterInfo::CharacterInfo(COINS cost, string defaultFile, string selectedFile, Vector2 position)
{
    this->cost = cost;
    this->button = Button(defaultFile, Vector2(1, 1), 200, selectedFile, Vector2(1, 1), 200, "", Vector2(1, 1), 200, position, false);
}

void CharacterInfo::updateButton(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    button.Update(gameTime, mouseState, prevMouseState);
}

void CharacterInfo::drawButton()
{
    button.Draw(Vector2());
}

bool CharacterInfo::clickedButton()
{
    return button.wasJustReleased();
}

bool CharacterInfo::buyCharacter(COINS* coins)
{
    bool result = *coins >= cost;
    
    if(result)
        *coins -= cost;
    
    return result;
}

COINS CharacterInfo::getCost() { return cost; }