#ifndef BULLETPOOL_HEADERGAURD
#define BULLETPOOL_HEADERGAURD

#include <SGE_Math.h>

class Bullet;

class BulletPool
{
public:

	BulletPool();

	void Fire(const SGE::SVector2 & pos, const SGE::SVector2 & vel);

	void Load(const unsigned int numBullets);
	void Load(const unsigned int numBullets, const char* textureName);
	void UnLoad();
	void Update(float deltaTime);
	void Render();
private:

	unsigned int mNumBullets;
	unsigned int mCurBulletIndex;
	Bullet * mBullets;

	bool mInitialized;
};

#endif
