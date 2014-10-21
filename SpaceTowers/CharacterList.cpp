//
//  CharacterList.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 7/3/14.
//
//

#include "stdafx.h"
#include "CharacterList.h"


CharacterList::CharacterList()
{
    
}


CharacterList::CharacterList(vector<CharacterInfo*> info)
{
    characters = info;
    createdCharacters = vector<Character*>();
}

void CharacterList::Update(GameTime* gameTime, ALLEGRO_MOUSE_STATE *mouseState, ALLEGRO_MOUSE_STATE *prevMouseState, COINS *coins, bool goingRight)
{
    for(int i = 0; i < characters.size(); i++)
    {
        characters[i]->updateButton(gameTime, mouseState, prevMouseState);
        
        if(characters[i]->clickedButton())
            createCharacter(i, coins, goingRight);
    }
}

void CharacterList::Draw()
{
    for(int i = 0; i < characters.size(); i++)
        characters[i]->drawButton();
}

CharacterInfo* CharacterList::getCharacterInfo(int index)
{
    if(index >= characters.size() || index < 0)
        return NULL;
    
    return characters[index];
}

size_t CharacterList::getCharacterInfoCount()
{
    return characters.size();
}

vector<Character*> CharacterList::getCreatedCharacters()
{
    vector<Character*> returnVal = createdCharacters;
    
    createdCharacters.clear();
    
    return returnVal;
}

void CharacterList::createCharacter(int index, COINS* coins, bool goingRight)
{
    Character* c = characters[index]->createCharacter(coins, goingRight);
    
    if(c != NULL)
        createdCharacters.push_back(c);
}

