#ifndef ENITITY_HEADERGAURD
#define ENITITY_HEADERGAURD

#include "GameObject.h"

class Entity : public GameObject
{
public:
	Entity();
	virtual ~Entity();

	void SetSpeed(const float speed);
	float GetSpeed() const;

	virtual void Kill() = 0;

protected:
	float mSpeed;

};

#endif