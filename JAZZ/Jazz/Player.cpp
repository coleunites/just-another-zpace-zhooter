#include "Player.h"

#include "SGE.h"

using namespace SGE;

Player::Player(unsigned int lives)
	: mLives(lives)
{

}

Player::~Player()
{

}

void Player::Load() 
{
	mSprite.Load("Fighter.png");
}

void Player::Unload()
{
	mSprite.Unload();
}

void Player::Render()
{
	SVector2 spriteHalfDim(static_cast<float>(mSprite.GetWidth()), static_cast<float>(mSprite.GetHeight()));
	spriteHalfDim *= 0.5f;
	mSprite.SetPosition(mPos - spriteHalfDim);
	mSprite.Render();
}

void Player::Update(const float deltaTime)
{
	const int kScreenwidth = IniFile_GetInt("WinWidth", 800);
	const int kScreenheight = IniFile_GetInt("WinHeight", 600);
	SVector2 movement(0.0f, 0.0f);

	SVector2 spriteHalfDim(static_cast<float>(mSprite.GetWidth()), static_cast<float>(mSprite.GetHeight()));
	spriteHalfDim *= 0.5f;

	if (Input_IsKeyDown(Keys::RIGHT) && mPos.x + spriteHalfDim.x < kScreenwidth)
	{
		movement.x = 1;
	}
	else if (SGE::Input_IsKeyDown(Keys::LEFT) && mPos.x - spriteHalfDim.x > 0.0f)
	{
		movement.x = -1;
	}
	if (SGE::Input_IsKeyDown(Keys::UP) && mPos.y - spriteHalfDim.y > 0.0f)
	{
		movement.y = -1;
	}
	else if (SGE::Input_IsKeyDown(Keys::DOWN) && mPos.y + spriteHalfDim.y < kScreenheight)
	{
		movement.y = 1;
	}

	movement.Normalize();
	movement *= mSpeed * deltaTime;

	mPos += movement;
}

void Player::Kill()
{

}

unsigned int Player::GetLives() const
{
	return mLives;
}
