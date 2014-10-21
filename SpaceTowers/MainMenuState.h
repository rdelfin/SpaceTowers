/*!
 * @header Main Menu State
 * State for the main menu (openning doors)
 * @author Ricardo Delfin Garcia
 * @language C++
 * @version 1.0
 */
#pragma once

#include "Vector2.h"
#include "GameState.h"
#include "GameObject.h"
#include "Button.h"
#include "PlanetButton.h"

/*!
 * Game state for the main menu. This has two openning doors with a button to start the game.
 * It also has planets in the background for preloading
 * the @link PlanetMenuState Planet Menu State @/link and having the planets display their text upon
 * hovering them. Is child class of @link GameState GameState @/link
 * @abstract The game state for the main menu (openning doors with a start game button). 
 * Check @link GameState GameState @/link for usage details
 * @updated 2014-07-05
 */
class MainMenuState : public GameState {
    
public:
    MainMenuState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState, ALLEGRO_FONT* font);
    
    /*!
     *  Method for the updating of all the game logic inside the game state. It mainly moves the doors
     *  arround and updates the button, as well as obtaining information from it. In adition to this,
     *  this method also updates the planet buttons for dispaly and hovering while the doors open.
     *
     *  @param gameTime Instance of GameTime* that contains all the information about the time since
     *  the game began as well as the time since the last game loop.
     */
    void Update(GameTime* gameTime);
	
    /*!
     *  Method used for drawing all objects on the screen. Here, it draws the background, the planets,
     *  the doors and the buttons, all with the animation they might require (said animation is created
     *  in the update method but actually drawn here)
     */
    void Draw();
    
    
    /*!
     *  Obtains a copy of the entire list of planets. The purpouse of this method is so that this list
     *  can be passed on to the PlanetMenuState so it may continue with the same planet positions as
     *  the ones found here.
     *
     *  @return A vector with the list of PlanetButton's
     */
    vector<PlanetButton> getPlanets();
    
    
    ~MainMenuState();
    
private:
    ALLEGRO_BITMAP *background;
    ALLEGRO_FONT* font;
    GameObject leftDoor, rightDoor;
    Button mainButton;
    bool opening;
    vector<PlanetButton> planets;
    
};