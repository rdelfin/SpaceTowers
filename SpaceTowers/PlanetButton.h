/*!
 *  @header Planet Button
 *  File with the Planet Button class
 *  @author Ricardo Delfin Garcia
 *  @version 1.0
 */

#pragma once

#include "Vector2.h"
#include "GameTime.h"

/*!
 *  A planet button. These rotate arround a point at a fixed speed and also rotate around
 *  their center. When hovered on, they stop. You can also stop a planet if any other planet is hovered,
 *  using the anyHovered variable in the @link Update @/link method. They also display text when they are
 *  hovered.
 *  @abstract The class for a rotating, planet button. Displays text and stops rotating round the
 *  center.
 *  @updated 2014-07-05
 */
class PlanetButton {

public:
    PlanetButton(string text, ALLEGRO_FONT* font, string file, Vector2 center, double distance, double initialAngle, double angularVel, double rotationVel);
    
    /*!
     *  Update method for the hovering. This will stop the planet if the mouse is on top of it, by
     *  updating an internal boolean value that can be obtained with the @link isHovered @/link method.
     *  This has to be called BEFORE the Update method, so that the planets are stopped before they are
     *  moved arround.
     *
     *  @param mouseState     Instance of ALLEGRO_MOUSE_STATE* for getting the current information about
     *  the position of the mouse as well as the buttons
     *  @param prevMouseState Instance of ALLEGRO_MOUSE_STATE* for getting the information about the
     *  mouse position and buttons from <b>the previous frame</b>.
     */
    void UpdateHover(ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);
    
    /*!
     *  General update method. Here, you will find all the movement logic. It updates the angles for
     *  both rotation arround the planet's center as well as the center defined in the constructor.
     *  It is recommended that this method is called after UpdateHover of ALL the planet other buttons
     *  so the anyHovered parameter can be calculated properly
     *
     *  @param gameTime   Instance of GameTime* that keeps track of the time since the begining of
     *  the game as well as the time since the last itteration of the update cycle
     *  @param anyHovered boolean value which, if true, stops the planet and displays the text as if
     *  it were hovered. It is recommended that this value be true if there is any other planet being
     *  hovered at the same time.
     */
    void Update(GameTime* gameTime, bool anyHovered);
    
    /*!
     *  General drawing method. Draws the text according to boolean values set in the update methods.
     *  It also draws the planets so that they are rotating. The images and text drawn are passed in
     *  the constructor.
     */
    void Draw();
    
    /*!
     *  Method that tells you whether the planet is being hovered by the mouse in the current cycle.
     *  It is recomended for calculating the value of anyHovered for the Update method.
     *
     *  @return True if the planet is hovered.
     */
    bool isHovered();
    
    /*!
     *  Method that tells you whether the button is currently being pressed by the mouse. This is
     *  determined by the update method.
     *
     *  @return True if the planet is pressed. False otherwise.
     */
    bool isPressed();
    
    ~PlanetButton();
    
private:
    Vector2 center, position;
    double distance, angle, angularVel, rotationVel, rotationAngle;
    ALLEGRO_BITMAP* img;
    bool selected, hovered, anyHovered;
    string text;
    ALLEGRO_FONT* font;
};