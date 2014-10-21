#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	
}

GameObject::GameObject(string path, Vector2 frameCount, int millPerFrame, Vector2 initPos)
{
	sprite = new Sprite(path.c_str(), frameCount, millPerFrame);
	position = initPos;
}

void GameObject::Update(GameTime* gameTime)
{
	sprite->Update(gameTime);

	velocity = velocity + acceleration * gameTime->getMillisecondsPerFrame();
	position = position + velocity * gameTime->getMillisecondsPerFrame();
}

void GameObject::Draw(Vector2 camPos)
{
	sprite->Draw(position - camPos);
}


Vector2 GameObject::getFrameSize() { return sprite->getFrameSize(); }
Vector2 GameObject::getImageSize() { return sprite->getImageSize(); }
Vector2 GameObject::getFrameCount() { return sprite->getFrameCount(); }
Vector2 GameObject::getCurrentFrame() { return sprite->getCurrentFrame(); }

GameRectangle GameObject::getRectangle()
{
    return GameRectangle(position.x, position.y, getFrameSize().x, getFrameSize().y);
}

GameObject::~GameObject(void)
{
}
