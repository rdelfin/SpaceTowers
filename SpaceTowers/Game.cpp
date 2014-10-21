#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "PlanetMenuState.h"
#include "GameLevelState.h"

Game::Game()
    : BaseGame(Vector2(1024, 768), WINDOW, "Space Towers WORKING TITLE", 30)
{
    font = al_load_font("assets/fonts/Harabara.ttf", 18, NULL);
    gameState = new MainMenuState(getWindowSize(), &keyState, &prevKeyState, &mouseState, &prevMouseState, font);
    state = 0;
}

void Game::Update(GameTime* gameTime)
{
    gameState->Update(gameTime);
    
    if(!gameState->isRunning())
    {
        if(state == 0)
        {
            vector<PlanetButton> planets = ((MainMenuState*)gameState)->getPlanets();
            delete gameState;
            state++;
            gameState = new PlanetMenuState(getWindowSize(), &keyState, &prevKeyState, &mouseState, &prevMouseState, planets);
        }
        else if(state == 1)
        {
            PlanetMenuState* castedState = (PlanetMenuState*)gameState;
            int endState = castedState->getEndState();
            
            if(endState == 1)
            {
                state++;
                delete gameState;
                gameState = new GameLevelState(getWindowSize(), &keyState, &prevKeyState, &mouseState, &prevMouseState);
            }
            else
            {
                stop();
            }
        }
    }
}

void Game::Draw(GameTime* gameTime)
{
    gameState->Draw();
}

Game::~Game(void)
{
    this->BaseGame::~BaseGame();
    delete gameState;
    al_destroy_font(font);
}

int main(int argc, char** argv)
{
    BaseGame* game = new Game();
	game->run();
	delete game;
    
    return 0;
}
