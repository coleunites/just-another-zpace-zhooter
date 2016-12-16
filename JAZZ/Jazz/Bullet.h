#ifndef BULLET_HEADERGAURD
#define BULLET_HEADERGAURD

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();

	virtual void Load() override;
	void Load(const char* textureName);
	virtual void Unload() override;
	virtual void Render() override;
	virtual void Update(const float deltaTime) override;

	SGE::SVector2 GetSpriteDim();

	void Fire(const SGE::SVector2 & pos, const SGE::SVector2 & vel);
	void Kill();

	bool IsActive() const;

private:
	SGE::SVector2 mVel;
	bool mActive;
};

#endif;