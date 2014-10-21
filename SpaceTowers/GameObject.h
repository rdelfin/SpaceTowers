#include "Sprite.h"
#include "GameTime.h"
#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(string file, Vector2 frameCount, int millPerFrame, Vector2 initialPosition);
    
	virtual void Update(GameTime*);
	virtual void Draw(Vector2 camPos);

	~GameObject(void);
	
	Vector2 position, velocity, acceleration;
    
    Vector2 getFrameSize();
	Vector2 getImageSize();
	Vector2 getFrameCount();
	Vector2 getCurrentFrame();
    
    /*!
     *  Gets the bounding rectangle for the GameObject. Used mainly for collision and for measuring
     *  distances.
     *
     *  @return The bounding rectangle for the GameObject as a GameRectangle
     */
    virtual GameRectangle getRectangle();

protected:
	Sprite* sprite;

};

