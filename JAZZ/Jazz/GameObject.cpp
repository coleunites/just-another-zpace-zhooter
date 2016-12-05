#include "GameObject.h"

GameObject::GameObject()
	: mPos(0.0f, 0.0f)
{
}

GameObject::~GameObject()
{
}

SGE::SVector2 GameObject::GetPosition() const
{
	return mPos;
}

void GameObject::SetPosition(const SGE::SVector2 pos)
{
	mPos = pos;
}

void GameObject::SetSprite(const char * spriteName)
{
	mSprite.Load(spriteName);
}