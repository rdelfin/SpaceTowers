//
//  PlanetButton.cpp
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/22/14.
//
//

#include "stdafx.h"

#include "GameRectangle.h"
#include "PlanetButton.h"

PlanetButton::PlanetButton(string text, ALLEGRO_FONT* font, string file, Vector2 center, double distance, double initialAngle, double angularVel, double rotationVel)
{
    this->center = center;
    this->distance = distance;
    this->angle = initialAngle;
    this->angularVel = angularVel;
    this->rotationVel = rotationVel;
    this->rotationAngle = 0;
    this->img = al_load_bitmap(file.c_str());
    this->selected = false;
    this->hovered = false;
    this->position = Vector2(center.x + distance*cos(angle), center.y + distance*sin(angle));
    this->text = text;
    this->font = font;
    this->anyHovered = false;
}

void PlanetButton::UpdateHover(ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
{
    Vector2 bmpSize = Vector2(al_get_bitmap_width(img), al_get_bitmap_height(img));
    GameRectangle rect(position.x - bmpSize.x / 2, position.y - bmpSize.y / 2, bmpSize.x, bmpSize.y);
    
    this->hovered = rect.contains(Vector2(mouseState->x, mouseState->y));
    this->selected = !al_mouse_button_down(mouseState, 1) && al_mouse_button_down(prevMouseState, 1) && hovered;
}

void PlanetButton::Update(GameTime* gameTime, bool anyHovered)
{
    this->anyHovered = anyHovered;
    
    //Orbit around center while no other planet is hovered
    if(!anyHovered)
        angle += angularVel * gameTime->getMillisecondsPerFrame();
    
    rotationAngle +=  rotationVel * gameTime->getMillisecondsPerFrame();
    
    //Update position for rotating
    this->position = Vector2(center.x + distance*cos(angle), center.y + distance*sin(angle));
}

void PlanetButton::Draw()
{
    Vector2 imgSize = Vector2(al_get_bitmap_width(img), al_get_bitmap_height(img));
    int textWidth = al_get_text_width(font, text.c_str());
    int textHeight = al_get_font_ascent(font);
    
    
    al_draw_rotated_bitmap(img, imgSize.x / 2, imgSize.y / 2, position.x, position.y, rotationAngle, NULL);
    
    if(hovered)
        al_draw_text(font, al_map_rgb(255, 255, 255), position.x - textWidth / 2, position.y - textHeight / 2, NULL, text.c_str());
}

bool PlanetButton::isHovered() { return hovered; }

bool PlanetButton::isPressed() { return selected; }

PlanetButton::~PlanetButton()
{
    //al_destroy_bitmap(img);
}