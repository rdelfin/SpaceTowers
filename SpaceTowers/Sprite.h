#include "Vector2.h"
#include "GameTime.h"
#include "GameRectangle.h"

#pragma once
class Sprite
{
public:
	Sprite(void);
	Sprite(const char* file, Vector2 frameCount, int millPerFrame = 200, bool repeat = true);
    
	void Update(GameTime*);
	void Draw(Vector2);
	void Draw(GameRectangle destinationRectangle);
	
	void flip(bool = true);

	void setMillPerFrame(int);
    
    void setAngle(double);

	void reset();

	bool finishedAnim();

	Vector2 getFrameSize();
	Vector2 getImageSize();
	Vector2 getFrameCount();
	Vector2 getCurrentFrame();

	~Sprite(void);

private:
	ALLEGRO_BITMAP* sprite;
	Vector2 imageSize, frameSize, frameCount, currentFrame;
	int millPerFrame, timer;
	bool flipped, repeat, finished;
    double angle;
};

