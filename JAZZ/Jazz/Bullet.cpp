#include "Bullet.h"

#include <SGE.h>

using namespace SGE;

Bullet::Bullet()
	: mVel(0.0f, 0.0f)
	, mActive(false)
{

}

Bullet::~Bullet()
{

}

void Bullet::Load()
{
	mSprite.Load("bullet1");
}

void Bullet::Unload()
{
	mSprite.Unload();
}

void Bullet::Render()
{
	if (mActive)
	{
		SVector2 spriteHalfDim(static_cast<float>(mSprite.GetWidth()), static_cast<float>(mSprite.GetHeight()));
		spriteHalfDim *= 0.5f;
		mSprite.SetPosition(mPos - spriteHalfDim);
		mSprite.Render();
	}
}

void Bullet::Update(const float deltaTime)
{
	if (mActive)
	{
		mPos += mVel * deltaTime;
	}
}

void Bullet::Fire(const SGE::SVector2 pos, const SGE::SVector2 vel)
{
	mPos = pos;
	mVel = vel;
	mActive = true;
}

void Bullet::Kill()
{
	mActive = false;
}

bool Bullet::IsActive() const
{
	return mActive;
}