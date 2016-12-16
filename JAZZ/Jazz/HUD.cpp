#include "HUD.h"

#include "SGE.h"

using namespace SGE;

HUD::HUD()
	: mLivesSprites(nullptr)
	, mNumLivesSprites(0)
	, mCurNumLives(0)
{

}

HUD::~HUD()
{

}

void HUD::Load(const unsigned int lives, const char* textureName)
{
	mCurNumLives = lives;
	mNumLivesSprites = lives;

	mLivesSprites = new SGE_Sprite[lives];
	for (unsigned int i = 0; i < lives; ++i)
	{
		mLivesSprites[i].Load(textureName);
	}

	mTextureName.assign(textureName);
}

void HUD::UnLoad()
{
	for (unsigned int i = 0; i < mNumLivesSprites; ++i)
	{
		mLivesSprites[i].Unload();
	}

	delete[] mLivesSprites;
	mLivesSprites = nullptr;

	mNumLivesSprites = 0;
	mCurNumLives = 0;

	mTextureName.clear();
}

void HUD::Render()
{
	const float kScreenwidth = static_cast<float>(IniFile_GetInt("WinWidth", 800));
	const float kScreenheight = static_cast<float>(IniFile_GetInt("WinHeight", 600));

	SVector2 spriteDim(static_cast<float>(mLivesSprites[0].GetWidth()), 
		static_cast<float>(mLivesSprites[0].GetHeight()));

	for (unsigned int i = 0; i < mCurNumLives; ++i)
	{
		mLivesSprites[i].SetPosition(SVector2(kScreenwidth - (spriteDim.x * i + spriteDim.x), kScreenheight - spriteDim.y));

		mLivesSprites[i].Render();
	}
}

void HUD::UpdateNumLives(const unsigned int lives)
{
	if (lives > mNumLivesSprites)
	{
		std::string temp(mTextureName);
		UnLoad();
		Load(lives, temp.c_str());
	}
	else
	{
		mCurNumLives = lives;
	}
}