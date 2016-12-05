#include "Entity.h"

Entity::Entity()
	: mSpeed(0.0f)
{

}

Entity::~Entity()
{

}

void Entity::SetSpeed(const float speed)
{
	mSpeed = speed;
}

float Entity::GetSpeed() const
{
	return mSpeed;
}