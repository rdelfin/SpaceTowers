//
//  Button.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/18/14.
//
//

#include "stdafx.h"
#include "Button.h"

Button::Button()
{
    
}

Button::Button(string defaultFile, Vector2 defaultFrameCount, int defaultMillPerFrame, string selectedFile, Vector2 selectedFrameCount, int selectedMillPerFrame, string hoverFile, Vector2 hoverFrameCount, int hoverMillPerFrame, Vector2 initialPosition, bool hasHover)
    : GameObject(defaultFile, defaultFrameCount, defaultMillPerFrame, initialPosition)
{
    if(hasHover)
        this->hover = new Sprite(hoverFile.c_str(), hoverFrameCount, hoverMillPerFrame);
    
    this->selected = new Sprite(selectedFile.c_str(), selectedFrameCount, selectedMillPerFrame);
    this->hasHover = hasHover;
    this->hovered = false;
    this->pressed = false;
    this->justReleased = false;
}

void Button::Update(GameTime* gameTime, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    if(hasHover)
        this->hover->Update(gameTime);
    
    this->selected->Update(gameTime);
    GameObject::Update(gameTime);
    
    GameRectangle rect(position.x, position.y, sprite->getFrameSize().x, sprite->getFrameSize().y);
    
    this->hovered = rect.contains(Vector2(mouseState->x, mouseState->y));
    
    
    this->justReleased = !al_mouse_button_down(mouseState, 1) && al_mouse_button_down(prevMouseState, 1) && hovered;
    this->pressed = al_mouse_button_down(mouseState, 1) && hovered;
}

void Button::Draw(Vector2 camPos)
{
    /* State:
     * 0 - Default
     * 1 - Hover
     * 2 - Press
     */
    int state = 0;
    
    if(pressed)
        state = 2;
    else if(hovered && hasHover)
        state = 1;
    
    
    if(state == 0)
        GameObject::Draw(camPos);
    else if(state == 1)
        hover->Draw(position - camPos);
    else if(state == 2)
        selected->Draw(position - camPos);
}

bool Button::isPressed() { return pressed; }

bool Button::wasJustReleased() { return justReleased; }