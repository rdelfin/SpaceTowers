/*!
 * @header Game
 * This is the main file for the game. The main method can be found in the joint cpp file. From here,
 * the entire program runs.
 * @author Ricardo Delfin Garcia
 * @language C++
 * @version 1.0
 */

#pragma once
#include "BaseGame.h"
#include "GameState.h"


/*!
 *  The main class for the entire program. From here, the @link GameState Game States @/link
 *  are managed, created and destroyed. This class extends @link BaseGame BaseGame @/link which has the
 *  entire game loop logic as well as allegro initialization. Here you will only find the state 
 *  managment.
 *  @abstract This is the main class for the entire program from where all states are inizialized
 *  @updated 2014-07-04
 */
class Game : public BaseGame
{
public:
	Game();
    
    /*!
     *  Method with the entire update logic. It is called regularly, after a speficied time that is given
     *  by the fps parameter in the BaseGame constructor (here set to 30 fps)
     *
     *  @param gameTime Instance used to keep track of time since the begining of the game, and since
     *  each call of the Update Method
     */
	virtual void Update(GameTime* gameTime);
    
    /*!
     *  Method with the entire drawing. It only really draws the gameState. This is called periodically,
     *  in this case 30 times a second (30 fps).
     *
     *  @param gameTime Instance used to keep track of time since the begining of the game, and since
     *  each call of the Update Method
     */
	virtual void Draw(GameTime* gameTime);

	~Game(void);
private:
    GameState* gameState;
    int state;
    
    ALLEGRO_FONT* font;
    
};

