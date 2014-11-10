//
//  MainMenuState.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/17/14.
//
//

#include "stdafx.h"
#include "MainMenuState.h"

MainMenuState::MainMenuState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, ALLEGRO_FONT* font)
    : GameState(screenSize, keyState, prevKeyState, mouseState, prevMouseState)
{
    this->font = font;
    
    background = al_load_bitmap("assets/img/selectGameScreen/Starfield.png");
    leftDoor = GameObject("assets/img/selectGameScreen/leftblastdoor.png", Vector2(1, 1), 30, Vector2());
    rightDoor = GameObject("assets/img/selectGameScreen/Rightblastdoor.png", Vector2(1, 1), 30, Vector2(457, 0));
    
    //457 = 559 (size of left door) - 102 (overlap between doors)
    
    mainButton = Button("assets/img/selectGameScreen/StartButton.png", Vector2(1, 1), 100, "assets/img/selectGameScreen/StartButton.png", Vector2(1, 1), 100, "assets/img/selectGameScreen/StartButtonHover.png", Vector2(2, 1), 100, Vector2(300, 200), true);
    
    opening = false;
    
    /***********************************************************************************************
     ****************************************** Planets ********************************************
     ***********************************************************************************************/
    Vector2 center = Vector2(getScreenSize().x / 2, getScreenSize().y / 2);
    planets.push_back(PlanetButton("Play", font, "assets/img/gameMenuCircles/Center.png", center, 0, 0, 0.001, 0.001));
    planets.push_back(PlanetButton("Instructions", font, "assets/img/gameMenuCircles/Planet1.png", center, 175, M_PI / 2, 0.0003, 0.002));
    planets.push_back(PlanetButton("Back", font, "assets/img/gameMenuCircles/Planet3.png", center, 350, M_PI, -0.0002, -0.0015));
    planets.push_back(PlanetButton("Quit", font, "assets/img/gameMenuCircles/Planet2.png", center, 410, M_PI, -0.00015, 0.003));
}

void MainMenuState::Update(GameTime* gameTime)
{
    //Updates
    leftDoor.Update(gameTime);
    rightDoor.Update(gameTime);
    mainButton.Update(gameTime, mouseState, prevMouseState);
    
    
    //Open sequence code
    if(opening)
    {
        leftDoor.velocity = Vector2(-0.1, 0);
        rightDoor.velocity = Vector2(0.1, 0);
    }
    else if(mainButton.wasJustReleased())
        opening = true;
    
    //End state
    if(rightDoor.position.x > getScreenSize().x)
        stop();
    
    //Planets
    bool anyHovered = false;
    for(unsigned int i = 0; i < planets.size(); i++)
    {
        planets[i].UpdateHover(mouseState, prevMouseState);
        anyHovered = anyHovered || planets[i].isHovered();
    }
    
    for(unsigned int i = 0; i < planets.size(); i++)
        planets[i].Update(gameTime, anyHovered);
    
}

void MainMenuState::Draw()
{
    //Background
    al_draw_bitmap(background, 0, 0, 0);
    
    //Planets
    for(unsigned int i = 0; i < planets.size(); i++)
        planets[i].Draw();
    
    //Doors
    leftDoor.Draw(Vector2());
    rightDoor.Draw(Vector2());
    
    //Button
    if(!opening)
        mainButton.Draw(Vector2());
    
    
}

vector<PlanetButton> MainMenuState::getPlanets() { return planets; }

MainMenuState::~MainMenuState()
{
    al_destroy_bitmap(background);
}