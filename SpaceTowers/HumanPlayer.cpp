//
//  HumanPlayer.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/29/14.
//
//

#include "stdafx.h"
#include "HumanPlayer.h"

#include "SpaceMarine.h"

HumanPlayer::HumanPlayer()
{

}

HumanPlayer::HumanPlayer(string towerFile, int xOffset, int yOffset, Vector2 mapSize, COINS initialCredits, COINS initialCreditsPerSecond, double yCharacterOffset, bool goingRight, vector<CharacterInfo*> info, double towerHp)
    : Player(towerFile, xOffset, yOffset, mapSize, initialCredits, initialCreditsPerSecond, yCharacterOffset, goingRight, info, towerHp)
{
    this->font = al_load_ttf_font("assets/fonts/checkbook.ttf", 15, 0);
}

void HumanPlayer::addCharacters(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    characterList.Update(gameTime, mouseState, prevMouseState, &credits, goingRight);
}

void HumanPlayer::Draw(Vector2 camPos)
{
    Player::Draw(camPos);

    characterList.Draw();

    al_draw_textf(font, al_map_rgb(255, 255, 0), 10, 10, 0, "Coins: %ld", credits);
}
