#include "Enemy.h"

#include"SGE.h"

using namespace SGE;

Enemy::Enemy()
	: mActive(false)
{

}

Enemy::~Enemy()
{

}

void Enemy::Load() 
{
	mSprite.Load("stone.png");
}

void Enemy::Unload()
{
	mSprite.Unload();
}

void Enemy::Render()
{
	SVector2 spriteHalfDim(static_cast<float>(mSprite.GetWidth()), static_cast<float>(mSprite.GetHeight()));
	spriteHalfDim *= 0.5f;
	mSprite.SetPosition(mPos - spriteHalfDim);
	mSprite.Render();
}

void Enemy::Update(const float deltaTime)
{
	if (mActive)
	{
		//Temp movement code
		const int kScreenheight = IniFile_GetInt("WinHeight", 600);
		SVector2 movement(0.0f, 1.0f);

		SVector2 spriteHalfDim(static_cast<float>(mSprite.GetWidth()), static_cast<float>(mSprite.GetHeight()));
		spriteHalfDim *= 0.5f;

		movement.Normalize();
		movement *= mSpeed * deltaTime;

		mPos += movement;

		if (mPos.y > (float)kScreenheight)
		{
			mPos.y = -spriteHalfDim.y;
		}
	}
}

void Enemy::Kill()
{
	mActive = false;
}

void Enemy::Activate()
{
	mActive = true;
}