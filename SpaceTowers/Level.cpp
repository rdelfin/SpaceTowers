//
//  Level.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/25/14.
//
//

#include "stdafx.h"

#include "Level.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SpaceMarine.h"
#include "SuperSpaceMarine.h"

//CONSTANT DEFINITION
const double Level::CAM_SPEED = 0.3;

Level::Level(Vector2 screenSize)
{
    vector<CharacterInfo*> infoComputer;
    vector<CharacterInfo*> infoHuman;
    infoComputer.push_back(new SpaceMarineInfo(Vector2(20, 700)));
    infoHuman.push_back(new SpaceMarineInfo(Vector2(20, 700)));
    infoHuman.push_back(new SuperSpaceMarineInfo(Vector2(80, 700)));
    
    this->camPos = Vector2();
	this->screenSize = screenSize;
    this->human = new HumanPlayer("assets/img/levels/towers/left1.png", 50, 78, Vector2(2000, 768), 0, 1, 100, true, infoHuman, 1000);
    this->computer = new ComputerPlayer("assets/img/levels/towers/right1.png", 50, 78, Vector2(2000, 768), 0, 1, 100, false, infoComputer, 1000);
    
    background = al_load_bitmap("assets/img/levels/backgrounds/1.png");
}

void Level::Update(GameTime *gameTime, ALLEGRO_KEYBOARD_STATE *keyState, ALLEGRO_KEYBOARD_STATE *prevKeyState, ALLEGRO_MOUSE_STATE *mouseState, ALLEGRO_MOUSE_STATE *prevMouseState)
{
    human->Update(gameTime, keyState, prevKeyState, mouseState, prevMouseState, computer);
    computer->Update(gameTime, keyState, prevKeyState, mouseState, prevMouseState, human);
    
    bool right = al_key_down(keyState, ALLEGRO_KEY_RIGHT);
    bool left = al_key_down(keyState, ALLEGRO_KEY_LEFT);
    if(right != left)
    {
		//Uses game time to ensure smooth movement independent of framerate
		double currCamSpeed = CAM_SPEED * gameTime->getMillisecondsPerFrame();

        if(right) {
			if(camPos.x + screenSize.x + currCamSpeed <= al_get_bitmap_width(background))
				camPos.x += currCamSpeed;
		}
        else if(camPos.x - currCamSpeed >= 0)
			camPos.x -= currCamSpeed;
    }
}

void Level::Draw()
{
    al_draw_bitmap(background, -camPos.x, -camPos.y, NULL);
    
    human->Draw(camPos);
    computer->Draw(camPos);
}