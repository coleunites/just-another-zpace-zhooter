#ifndef BULLETPOOL_HEADERGAURD
#define BULLETPOOL_HEADERGAURD

class Bullet;

class BulletPool
{
public:

private:
	unsigned int mNumBullets;
	unsigned int mCurBulletIndex;
	Bullet * mBullets;
};

#endif
