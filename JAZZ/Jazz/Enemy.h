#ifndef ENEMY_HEADERGAURD
#define ENEMY_HEADERGAURD

#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual void Update(const float deltaTime) override;

	virtual void Kill() override;

	void Activate();

private:
	bool mActive;
};

#endif
