#include "BulletPool.h"

#include"Bullet.h"

#include <SGE.h>

using namespace SGE;

BulletPool::BulletPool()
	: mNumBullets(0)
	, mCurBulletIndex(0)
	, mBullets(nullptr)
	, mInitialized(false)
{
}

void BulletPool::Fire(const SGE::SVector2 & pos, const SGE::SVector2 & vel)
{
	//ASSERT HERE
	mBullets[mCurBulletIndex].Fire(pos, vel);
	mCurBulletIndex = ++mCurBulletIndex % mNumBullets;
}

void BulletPool::Load(const unsigned int numBullets)
{
	//ASSERT HERE

	mNumBullets = numBullets;
	mCurBulletIndex = 0;

	mBullets = new Bullet[numBullets];

	for (unsigned int i = 0; i < mNumBullets; ++i)
	{
		mBullets[i].Load();
	}

	mInitialized = true;
}

void BulletPool::Load(const unsigned int numBullets, const char* textureName)
{
	//ASSERT HERE
	mNumBullets = numBullets;
	mCurBulletIndex = 0;

	mBullets = new Bullet[numBullets];

	for (unsigned int i = 0; i < mNumBullets; ++i)
	{
		mBullets[i].Load(textureName);
	}

	mInitialized = true;
}

void BulletPool::UnLoad()
{
	//ASSERT HERE

	for (unsigned int i = 0; i < mNumBullets; ++i)
	{
		mBullets[i].Unload();
	}

	delete[] mBullets;
	mBullets = nullptr;

	mNumBullets = 0;
	mCurBulletIndex = 0;

	mInitialized = false;
}

void BulletPool::Update(float deltaTime)
{
	//ASSERT HERE
	const int kScreenwidth = IniFile_GetInt("WinWidth", 800);
	const int kScreenheight = IniFile_GetInt("WinHeight", 600);

	SVector2 spriteHalfDim = mBullets[0].GetSpriteDim();
	spriteHalfDim *= 0.5f;

	SVector2 curBulletPos;

	for (unsigned int i = 0; i < mNumBullets; ++i)
	{
		mBullets[i].Update(deltaTime);

		curBulletPos = mBullets[i].GetPosition();

		if (mBullets[i].IsActive() && 
			(curBulletPos.x - spriteHalfDim.x > kScreenwidth || curBulletPos.x + spriteHalfDim.x < 0.0f ||
			curBulletPos.y + spriteHalfDim.y < 0.0f || curBulletPos.y - spriteHalfDim.y > kScreenheight))
		{
 			mBullets[i].Kill();
		}
	}
}

void BulletPool::Render()
{
	//ASSERT HERE
	for (unsigned int i = 0; i < mNumBullets; ++i)
	{
		mBullets[i].Render();
	}
}