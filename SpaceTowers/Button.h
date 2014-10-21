//
//  Button.h
//  SpaceTowersXcode
//
//  Created by Ricardo Delfin on 6/18/14.
//
//

#pragma once

#include "GameObject.h"

class Button : public GameObject {
public:
    Button();
    Button(string defaultFile, Vector2 defaultFrameCount, int defaultMillPerFrame, string selectedFile, Vector2 selectedFrameCount, int selectedMillPerFrame, string hoverFile, Vector2 hoverFrameCount, int hoverMillPerFrame, Vector2 position, bool hasHover);
    
    virtual void Update(GameTime*, ALLEGRO_MOUSE_STATE*, ALLEGRO_MOUSE_STATE* prevMouseState);
	virtual void Draw(Vector2 camPos);
    
    bool isPressed();
    bool wasJustReleased();
    
private:
    Sprite *selected, *hover;
    bool hovered, pressed, hasHover, justReleased;
    
};

