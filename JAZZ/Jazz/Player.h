#ifndef PLAYER_HEADERGAURD
#define PLAYER_HEADERGAURD

#include "BulletPool.h"
#include "Entity.h"


class Player : public Entity
{
public:
	Player(unsigned int lives);
	virtual ~Player();

	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual void Update(const float deltaTime) override;

	virtual void Kill() override;

	unsigned int GetLives() const;

private:
	unsigned int mLives;
	SGE::SVector2 mBulletVel;
	BulletPool mBullets;
};

#endif
