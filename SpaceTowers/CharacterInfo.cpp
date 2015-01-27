
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
	priceFont = al_load_ttf_font("assets/fonts/checkbook.ttf", 12, 0);
}

void CharacterInfo::updateButton(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    button.Update(gameTime, mouseState, prevMouseState);
}

void CharacterInfo::drawButton()
{
    button.Draw(Vector2());

	//Text drawing
	char text[10];
	sprintf(text, "$%ld", cost);
	int width = al_get_text_width(priceFont, text);
	int textX = button.position.x + button.getFrameSize().x / 2 - width / 2;
	int textY = button.position.y + button.getFrameSize().y + TEXT_SPACE;
	al_draw_text(priceFont, al_map_rgb(255, 255, 0), textX, textY, 0, text);
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
