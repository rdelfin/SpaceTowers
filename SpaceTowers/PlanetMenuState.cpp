//
//  PlanetMenuState.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/22/14.
//
//

#include "stdafx.h"
#include "PlanetMenuState.h"


PlanetMenuState::PlanetMenuState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, vector<PlanetButton> planets)
    : GameState(screenSize, keyState, prevKeyState, mouseState, prevMouseState)
{
    background = al_load_bitmap("assets/img/selectGameScreen/Starfield.png");
    
    this->planets = planets;
}

void PlanetMenuState::Update(GameTime* gameTime)
{
    bool anyHovered = false;
    for(unsigned int i = 0; i < planets.size(); i++)
    {
        planets[i].UpdateHover(mouseState, prevMouseState);
        anyHovered = anyHovered || planets[i].isHovered();
    }
    
    for(unsigned int i = 0; i < planets.size(); i++)
        planets[i].Update(gameTime, anyHovered);
    
    for(int i = 0; i < planets.size(); i++)
    {
        if(planets[i].isPressed())
        {
            endState = i + 1;
            stop();
        }
    }
}

void PlanetMenuState::Draw()
{
    al_draw_bitmap(background, 0, 0, NULL);
    
    for(unsigned int i = 0; i < planets.size(); i++)
        planets[i].Draw();
}

int PlanetMenuState::getEndState()
{
    return endState;
}